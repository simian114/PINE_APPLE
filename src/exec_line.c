/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 05:21:23 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int check_redirection(char **cmd, int *fd_file)
{
	int ret;

	ret = 0;
	while (*cmd)
	{
		if (**cmd < 0)
		{
			ret = **cmd;
			break ;
		}
		cmd++;
	}
	if (ret == -1)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (ret == -2)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_APPEND , 0744);
	else if (ret == -3)
		*fd_file = open(*(cmd + 1), O_RDONLY);
	else
		*fd_file = 1;
	return (ret);
}

static void exec_cmds(char ***cmds, t_list *envs, char **envp)
{
	int fdd;
	int fd[2];
	pid_t pid;
	int redirection;
	int fd_file;

	fdd = 0;
	while (*cmds)
	{
		if (!cmd_switch(*cmds, envs))
		{
			pipe(fd);
			if ((pid = fork()) == -1)
				ft_putstr_fd("pid error.\n", 2);
			else if (pid == 0)
			{
				dup2(fdd, 0);
				if (*(cmds + 1))
					dup2(fd[1], 1);
				redirection = check_redirection(*cmds, &fd_file);
				if (fd_file < 0)
				{
					ft_putstr_fd("minishell: ", 2);
					ft_putendl_fd(strerror(errno), 2);
					exit(1);
				}
				else if ((redirection == -1 || redirection == -2) && !*(cmds + 1))
					dup2(fd_file, 1);
				else if (redirection == -3)
					dup2(fd_file, 0);
				close(fd[0]);
				fork_cmd_switch(*cmds, envs, envp, 1);
				exit(0);
			}
			else
			{
				wait(NULL);
				close(fd[1]);
				fdd = fd[0];
				// if (!*(cmd + 1) && is_same(**cmd, "echo") && is_same(*(*cmd + 1), "-n"))
					// ft_putstr_fd("%\n", 1);
			}
		}
		cmds++;
	}
}

void		exec_line(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**semicolon_mover;
	char	**args;
	char	***cmds;

	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		args = get_args(*semicolon_mover, envs);
		cmds = pipe_split(args);
		free_double_char(&args);
		exec_cmds(cmds, envs, envp);
		free_triple_char(&cmds);
		semicolon_mover++;
	}
	free_double_char(&semicolon);
	free(line);
}
