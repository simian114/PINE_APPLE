/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 12:52:50 by gmoon            ###   ########.fr       */
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
	char	*env_path_mover;

	if (ft_strncmp(*args, "/", 1) == 0 || ft_strncmp(*args, ".", 1) == 0)
	{
		ret = exec_fork(args[0], args, envp);
		if (ret == -1)
		{
			ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(*args, 2);
			exit(1);
		}
	}
	else
	{
		if (find_value(envs, "PATH"))
		{
			env_path = ft_strdup(find_value(envs, "PATH"));
			env_path_mover = env_path;
			while (*env_path_mover)
			{
				path = ft_substr(env_path_mover, 0, path_len(env_path_mover));
				env_path_mover += path_len(env_path_mover) + 1;
				program_tmp = ft_strjoin_free(path, char_to_str('/'));
				program = ft_strjoin_s1free(program_tmp, *args);
				ret = exec_fork(program, args, envp);
				free(program);
				if (ret >= 0)
					exit(0);
			}
			free(env_path);
			free(path);
		}
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd("command not found: ", 2);
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
