/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 21:19:16 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

// echo만 되게 해놨는데, 'echo'와 "echo"도 되게 고쳐야.

static void	command_switch(char **args, t_list *envs, char **envp)
{
	int fd = 1; // 임시
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
	else if (ft_strncmp(args[0], "./", 2) == 0)
		sh_exec(args[0], envp);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(args[0], 1);
	}
}

int check_redirection(char **cmd, char **filename)
{
	// 리다이렉션 체크.
	// filename 만들기.

	int ret;

	ret = 0;
	while (*cmd)
	{
		if (**cmd < 0)
		{
			ret = **cmd;
			cmd++;
			// *fliename = ft_strdup(*cmd); // 복제본 만들어야할까?
			*filename = *cmd; // 이렇게 해도 되나?
			break ;
		}
		cmd++;
	}
	return (ret);
}

void exec_cmd(char ***cmd, t_list *envs, char **envp)
{
	int fd[2];
	pid_t pid;
	int fdd;
	int status;

	int fd_file;
	char *filename;
	int redirection;

	fdd = 0; // 아직 모름.
	while (*cmd)
	{
		pipe(fd);
		if ((pid = fork()) == -1)
			ft_putstr_fd("pid error.\n", 2); // 임시
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(cmd + 1))
				dup2(fd[1], 1);
			redirection = check_redirection(*cmd, &filename);
			// printf("[rd:%d filename:%s]\n", redirection, filename);
			if (redirection == -1)
			{
				fd_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
				dup2(fd_file, 1);
			}
			else if (redirection == -2)
			{
				fd_file = open(filename, O_WRONLY | O_CREAT | O_APPEND , 0744);
				dup2(fd_file, 1);
			}
			else if (redirection == -3)
			{
				fd_file = open(filename, O_RDONLY);
				if (fd_file < 0)
				{
					ft_putstr_fd("minishell: ", 2);
					ft_putendl_fd(strerror(errno), 2);
					exit(1);
				}
				dup2(fd_file, 0); // 되나? 이게 문젠데.
			}
			close(fd[0]);
			command_switch(*cmd, envs, envp);
			// close(fd_file); // 해줘야하나?
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
// https://gist.github.com/iomonad/a66f6e9cfb935dc12c0244c1e48db5c8

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**semicolon_mover;

	if (!envp && !envs)
		printf("zz\n");
	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		char **args;
		char ***cmd;

		args = get_args(*semicolon_mover, envs);
		cmd = pipe_split(args);

		// // 출력 테스트
		// int test;
		// while (*cmd)
		// {
		// 	test = 0;
		// 	while (**cmd)
		// 	{
		// 		printf("%d: %s\n", test, **cmd);
		// 		(*cmd)++;
		// 		test++;
		// 	}
		// 	cmd++;
		// }

		exec_cmd(cmd, envs, envp); // 아직 정리도 완성도 X. 나중에...
		semicolon_mover++;
	}
	double_char_free(&semicolon);
}

// 수정할 점.
// [ ] echo "$HOME>me" 등 특문이 들어가면 다 돼야함. 현재는 띄어쓰기같은거만 분리되게 해놓음. - 나중에...
// [ ] fork를 도입하다보니 아직 exit랑 cd같은건 안됨.
// [ ] 아직 리다이렉션 구현 안함.
// [ ] free를 아직 신경 못씀. ... 쉬고 하자.
