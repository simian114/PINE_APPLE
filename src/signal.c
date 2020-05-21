/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:19:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 16:14:07 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sigint_handle(void)
{
	int		ppid;
	char	*cwd;

	ppid = getppid();
	if (ppid == g_core)
		exit(1);
	else
	{
		g_intt = 1;
		ft_putendl_fd(" ", 1);
		cwd = getcwd(0, 1024);
		ft_putstr_fd("\033[36m\033[3m\033[01m", 1);
		ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
		ft_putstr_fd("\033[35m", 1);
		ft_putstr_fd(" >> ", 1);
		ft_putstr_fd("\033[0m", 1);
		free(cwd);
	}
}

void		sigquit_handle(void)
{
	int		current;

	current = getpid();
	if (current == g_core)
		ft_putstr_fd("\e[2D\e[0K", 1);
	else
	{
		ft_putstr_fd("[1]    ", 2);
		ft_putnbr_fd(current, 2);
		ft_putendl_fd(" quit", 2);
		exit(1);
	}
}
