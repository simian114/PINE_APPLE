/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 00:07:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int exec_fork(char **argv, char **envp)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0] + 2, argv, envp) == -1)
			return (-1);
	}
	else
		wait(0);
	return (0);
}

void sh_exec(char *command, char **envp)
{
	char **argv;

	argv = ft_split(command, ' ');
	if (exec_fork(argv, envp) == -1)
	{
		ft_putstr_fd("moong_shell: no such file or directory: ", 1);
		ft_putendl_fd(argv[0], 1);
		// 뭔가 에러...관련 함수를 써야할 것 같은데? 일단은...
	}
	double_char_free(&argv);
}
