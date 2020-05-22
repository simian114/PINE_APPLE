/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:19:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/22 16:40:03 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sigint_handle(int signo)
{
	int		t;

	t = signo;
	signo = t;
	ft_putstr_fd("\e[2D\e[0K\n", 1);
	print_commandline();
}

void		sigquit_handle(int signo)
{
	int		current;
	int		t;

	t = signo;
	signo = t;
	current = getpid();
	if (current == g_core)
		ft_putstr_fd("\e[2D\e[0K", 1);
	else
	{
		if (current != g_core)
		{
			ft_putstr_fd("[1]    ", 2);
			ft_putnbr_fd(current, 2);
			ft_putendl_fd(" quit", 2);
			exit(1);
		}
	}
}
