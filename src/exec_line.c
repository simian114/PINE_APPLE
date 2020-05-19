/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 22:18:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_redirection(char **cmd, int *fd_file)
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
	// if (ret < 0)
	// printf("<%s>\n", *(cmd + 1));
	// printf("!%d!\n", ret);

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

static void exec_cmds(char ***cmds, t_list *envs, char **envp, int *wstatus)
{
	int fdd;
	int fd[2];
	pid_t pid;
	int redirection;
	int fd_file;

	fdd = 0;
	while (*cmds)
	{
		if (!cmd_switch(*cmds, envs, wstatus))
		{
			pipe(fd);
			if ((pid = fork()) == -1)
				ft_putstr_fd("pid error.\n", 2);
			else if (pid == 0)
			{
				dup2(fdd, 0);
				if (*(cmds + 1))
				{
					// printf("zz?\n");
					dup2(fd[1], 1);
				}
				redirection = check_redirection(*cmds, &fd_file);
				if (fd_file < 0)
				{
					ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
					ft_putstr_fd(strerror(errno), 2);
					ft_putstr_fd("\n", 2);
					exit(1);
				}
				else if ((redirection == -1 || redirection == -2) && !*(cmds + 1))
				{
					// printf("%d\n", fd_file);
					dup2(fd_file, 1);
				}
				else if (redirection == -3)
				{
					dup2(fd_file, 0);
				}
				close(fd[0]);
				fork_cmd_switch(*cmds, envs, envp, 1);
				exit(0);
			}
			else
			{
				wait(wstatus);
				close(fd[1]);
				fdd = fd[0];
				// if (!*(cmds + 1) && is_same(**cmds, "echo") && is_same(*(*cmds + 1), "-n"))
					// ft_putstr_fd("%\n", 1);
			}
		}
		cmds++;
	}
}

void		exec_line(char *line, t_list *envs, char **envp, int *wstatus)
{
	char	**semicolon;
	char	**semicolon_mover;
	char	**args;
	char	***cmds;

	if (!envp)
		printf("zz\n");
	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		args = get_args(*semicolon_mover, envs);
		cmds = pipe_split(args);

		// while (*cmds)
		// {
		// 	while (**cmds)
		// 	{
		// 		printf("[%s (%d)]\n", **cmds, ***cmds);
		// 		(*cmds)++;
		// 	}
		// 	(cmds)++;
		// }

		free_double_char(&args);
		exec_cmds(cmds, envs, envp, wstatus);
		free_triple_char(&cmds);
		semicolon_mover++;
	}
	store_status(envs, wstatus);
	free_double_char(&semicolon);
	free(line);
}
