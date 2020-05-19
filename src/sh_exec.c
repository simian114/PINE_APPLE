/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 21:33:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char **test(char **argv)
// {
// 	char	**ret;
// 	int		i;

// 	i = -1;
// 	while (argv[++i])
// 		;
// 	ret = (char **)malloc(sizeof(char *) * (i + 1));
// 	ret[i] = 0;
// 	i = -1;
// 	while (argv[++i])
// 	{
// 		if (ft_atoi(argv[i]) < 0)
// 		{
// 			if (ft_atoi(argv[i]) == -1)
// 				ret[i] = ft_strdup(">");
// 			else if (ft_atoi(argv[i]) == -2)
// 				ret[i] = ft_strdup(">>");
// 			else
// 				ret[i] = ft_strdup("<");
// 		}
// 		ret[i] = ft_strdup(argv[i]);
// 	}
// 	return (ret);
// }

static int exec_fork(char **argv, char **envp)
{
	int pid;
	// char	**ret;

	pid = fork();
	if (pid == 0)
	{
		// ret = test(argv);
		// if (execve(ret[0], ret, envp) == -1)
		if (execve(argv[0], argv, envp) == -1)
			return (-1);
			// exit(1);
	}
	else if (pid > 0)
		wait(0);
	return (0);
	// exit(0);
}

void sh_exec(char **args, char **envp)
{
	if (exec_fork(args, envp) == -1)
	{
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(*args, 2); // 에러 처리 통일 가능할 듯.
		exit(1);
	}
	exit(0);
}
