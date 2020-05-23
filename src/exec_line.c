/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/23 23:46:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_cmd(char **cmd, int redirection)
{
	int		i;
	int		size;
	char	**ret;

	size = get_argc(cmd);
	if (redirection < 0)
		size -= 2;
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	ret[size] = 0;
	i = -1;
	while (++i < size)
	{
		if (**cmd < 0)
			cmd += 2;
		ret[i] = ft_strdup(*cmd);
		cmd++;
	}
	return (ret);
}

static char	**init_fd(int fdd, char ***cmds, int fd[2])
{
	int		redirection;
	int		fd_file;

	dup2(fdd, 0);
	if (*(cmds + 1))
		dup2(fd[1], 1);
	redirection = check_redirection(*cmds, &fd_file);
	if (fd_file < 0)
	{
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	else if (redirection == -1 || redirection == -2)
		dup2(fd_file, 1);
	else if (redirection == -3)
		dup2(fd_file, 0);
	close(fd[0]);
	return (get_cmd(*cmds, redirection));
}

static void	parent_process(int *wstatus, int fd[2], int *fdd)
{
	wait(wstatus);
	close(fd[1]);
	*fdd = fd[0];
}

static void	exec_cmds(char ***cmds, t_list *envs, char **envp, int *wstatus)
{
	int		fdd;
	int		fd[2];
	pid_t	pid;
	char	**cmd;

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
				cmd = init_fd(fdd, cmds, fd);
				fork_cmd_switch(cmd, envs, envp, 1);
				free_double_char(&cmd);
				exit(0);
			}
			else
				parent_process(wstatus, fd, &fdd);
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

	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		args = get_args(*semicolon_mover, envs);
		cmds = pipe_split(args);
		free_double_char(&args);
		exec_cmds(cmds, envs, envp, wstatus);
		free_triple_char(&cmds);
		semicolon_mover++;
	}
	store_status(envs, wstatus);
	free_double_char(&semicolon);
	free(line);
}
