/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 10:47:42 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_fork(char **argv, char **envp)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			return (-1);
	}
	else if (pid > 0)
		wait(0);
	return (0);
}

void		sh_exec(char **args, char **envp)
{
	if (exec_fork(args, envp) == -1)
	{
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(*args, 2);
		exit(1);
	}
	exit(0);
}
