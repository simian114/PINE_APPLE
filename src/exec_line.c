/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/18 02:27:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	fork_cmd_switch(char **args, t_list *envs, char **envp, int fd)
{
	// int fd = 1; // 확정되면 없애자.

	if (is_command(*args, "echo"))
		sh_echo(args + 1, fd);
	else if (is_command(*args, "pwd"))
		sh_pwd(fd);
	else if (is_command(*args, "env"))
		sh_env(envs, fd);
	else if (is_command(*args, "export"))
		sh_env(envs, fd);
	else if (is_command(*args, "ls"))
		sh_ls(fd);
	else if (is_command(*args, "clear"))
		sh_clear(fd);
	else if (ft_strncmp(*args, "./", 2) == 0)
		sh_exec(args[0], envp);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(args[0], 1);
	}
}

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
	if (ret == -1)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (ret == -2)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_APPEND , 0744);
	else if (ret == -3)
		*fd_file = open(*(cmd + 1), O_RDONLY);
	return (ret);

}

int cmd_switch(char **cmd, t_list *envs)
{
	int ret;

	ret = 1;
	if (is_same(*cmd, "exit"))
		exit(0);
	else if (is_same(*cmd, "cd"))
		sh_cd(cmd, envs);
	else if (is_same(*cmd, "export") && *(cmd + 1))
		sh_export(cmd + 1, envs);
	else if (is_same(*cmd, "unset"))
		sh_unset(cmd + 1, envs);
	else
		ret = 0;
	return (ret);
}

void exec_process(char ***cmd, t_list *envs, char **envp)
{
	int fdd;
	int fd[2];
	pid_t pid;
	int redirection;
	int fd_file;
	int status;

	fdd = 0;
	while (*cmd)
	{
		if (!cmd_switch(*cmd, envs))
		{
			pipe(fd);
			if ((pid = fork()) == -1)
				ft_putstr_fd("pid error.\n", 2);
			else if (pid == 0)
			{
				dup2(fdd, 0);
				if (*(cmd + 1))
					dup2(fd[1], 1);
				redirection = check_redirection(*cmd, &fd_file);
				if (fd_file < 0)
				{
					ft_putstr_fd("minishell: ", 2);
					ft_putendl_fd(strerror(errno), 2);
					exit(1);
				}
				else if ((redirection == -1 || redirection == -2) && !*(cmd + 1))
					dup2(fd_file, 1);
				else if (redirection == -3)
					dup2(fd_file, 0);
				close(fd[0]);
				fork_cmd_switch(*cmd, envs, envp, 1);
				exit(1);
			}
			else
			{
				wait(&status);
				close(fd[1]);
				fdd = fd[0];
				// if (!*(cmd + 1) && is_same(**cmd, "echo") && is_same(*(*cmd + 1), "-n"))
					// ft_putstr_fd("%\n", 1);
			}
		}
		cmd++;
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

		// // 출력 테스트
//		int test;
//		while (*cmd)
//		{
//			test = 0;
//			while (**cmd)
//			{
//				printf("%d: %s\n", test, **cmd);
//				(*cmd)++;
//				test++;
//			}
//			cmd++;
//		}

		exec_process(cmds, envs, envp);
		double_char_free(&args);
		// triple_char_free(&cmds);
		semicolon_mover++;
	}
	double_char_free(&semicolon);
}
