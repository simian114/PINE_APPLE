/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 12:17:57 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_fork(char *program, char **argv, char **envp)
{
	int		pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(program, argv, envp) == -1)
			return (-1);
	}
	else if (pid > 0)
		wait(&status);
	return (status);
}

int		path_len(char *str)
{
	int	len;

	len = 0;
	while (*str && *str != ':')
	{
		len++;
		str++;
	}
	return (len);
}

#include <stdio.h>
void		sh_exec(char **args, char **envp, t_list *envs)
{
	int		ret;
	char	*env_path;
	char	*path;
	char	*program_tmp;
	char	*program;

	if (ft_strncmp(*args, "/", 1) == 0 || ft_strncmp(*args, ".", 1) == 0)
		ret = exec_fork(args[0], args, envp);
	else
	{
		if (find_value(envs, "PATH"))
			env_path = ft_strdup(find_value(envs, "PATH"));
		while (1)
		{
			int len;

			len = path_len(env_path);
			path = ft_substr(env_path, 0, len);
			if (len == 0)
			{
				free(path);
				break ;
			}
			env_path += len + 1;
			program_tmp = ft_strjoin_free(path, char_to_str('/'));
			program = ft_strjoin_s1free(program_tmp, *args);
			ret = exec_fork(program, args, envp);
			free(program);
			if (ret >= 0)
				exit(0);
		}
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m command not found: ", 2);
		ft_putendl_fd(*args, 2);
		exit(1);
	}
	// printf("%s\n", env_path);
	
	// ret = exec_fork(args, envp);
	// if (ret == -1)
	// {
	// 	ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
	// 	ft_putstr_fd(strerror(errno), 2);
	// 	ft_putstr_fd(": ", 2);
	// 	ft_putendl_fd(*args, 2);
	// 	exit(1);
	// }
	// else if (ret != -1 && ret != 0)
	// 	exit(1);
	// else
	// 	exit(0);
	// exit(0);
}
