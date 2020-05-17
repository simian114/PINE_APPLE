/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/18 00:55:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	command_switch(char **args, t_list *envs, char **envp)
{
	int fd = 1;
	if (is_command(args[0], "exit"))
		exit(0);
	else if (is_command(args[0], "echo"))
		sh_echo(args + 1, fd);
	else if (is_command(args[0], "pwd"))
		sh_pwd(fd);
	else if (is_command(args[0], "cd"))
		sh_cd(args, envs);
	else if (is_command(args[0], "env"))
		sh_env(envs, fd);
	else if (is_command(args[0], "export"))
		sh_export(args + 1, envs);
	else if (is_command(args[0], "unset"))
		sh_unset(args + 1, envs);
	else if (is_command(args[0], "ls"))
		sh_ls(fd);
	else if (is_command(args[0], "clear"))
		sh_clear(fd);
	else if (ft_strncmp(args[0], "./", 2) == 0)
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

void exec_cmd(char ***cmd, t_list *envs, char **envp)
{
	int fd[2];
	pid_t pid;
	int fdd;
	int status;

	int fd_file;
	int redirection;

	fdd = 0;
	while (*cmd)
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
			command_switch(*cmd, envs, envp);
			exit(1);
		}
		else
		{
			wait(&status);
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**semicolon_mover;

	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		char **args;
		char ***cmd;

		args = get_args(*semicolon_mover, envs);
		cmd = pipe_split(args);

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

		exec_cmd(cmd, envs, envp);
		semicolon_mover++;
	}
	double_char_free(&semicolon);
}
