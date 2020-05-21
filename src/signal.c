/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:19:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 10:53:16 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sigint_handle(void)
{
	int		current;

	current = getpid();
	if (g_core != current)
	{
		ft_putendl_fd("", 1);
		exit(1);
	}
	else
	{
		ft_putstr_fd("\e[2D\e[0K", 1);
		ft_putendl_fd("", 1);
		print_commandline();
	}
}

void		sigquit_handle(void)
{
	int		current;

	current = getpid();
	if (current != g_core)
	{
		ft_putstr_fd("[1]    ", 2);
		ft_putnbr_fd(current, 2);
		ft_putendl_fd(" quit", 2);
		exit(1);
	}
	else
		ft_putstr_fd("\e[2D\e[0K", 1);
}
