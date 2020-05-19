/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 22:44:14 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 17:54:14 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handling_redirection(char **cmd, char **file)
{
	int		fd;

	while (*cmd)
	{
		if (**cmd < 0)
		{
			if (**cmd == -1 || **cmd == -2)
				fd = open(*(cmd + 1), O_RDWR | O_CREAT, 0644);
			else if (**cmd == -3)
				fd = open(*(cmd + 1), O_RDONLY);
			if (fd < 0)
			{
				*file = ft_strdup(*(cmd + 1));
				return (-1);
			}
			if (fd > 0)
				close(fd);
			return (1);
		}
		cmd++;
	}
	return (0);
}

int		handling_redirection_2(int ret, int *wstatus, char *file)
{
	if (ret < 0)
	{
		*wstatus = 1;
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd(strerror(ENOENT), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(file, 2);
		free(file);
		return (1);
	}
	return (0);
}

int		cmd_switch(char **cmd, t_list *envs, int *wstatus)
{
	int		ret;
	int		temp;
	char	*file;

	ret = 1;
	if (is_same(*cmd, "exit"))
		exit(0);
	else if (is_same(*cmd, "cd") || is_same(*cmd, "export") ||
			is_same(*cmd, "unset"))
	{
		temp = handling_redirection(cmd, &file);
		handling_redirection_2(temp, wstatus, file);
			return (1);
		if (is_same(*cmd, "cd"))
			sh_cd(cmd, envs, wstatus);
		else if (is_same(*cmd, "export") && *(cmd + 1))
			sh_export(cmd + 1, envs);
		else if (is_same(*cmd, "unset"))
			sh_unset(cmd + 1, envs);
	}
	else
		ret = 0;
	return (ret);
}

//int		cmd_switch(char **cmd, t_list *envs, int *wstatus)
//{
//	int ret;
//
//	check_redirection(cmd, fd_file);
//	if (*fd_file > 0)
//		close(*fd_file);
//	if (errno != 0)
//	{
//		*wstatus = 1;
//		ft_putendl_fd("here", 2);
//		ft_putendl_fd(*cmd, 2);
//		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
//		ft_putendl_fd(strerror(errno), 2);
//		return (1);
//	}
//	ret = 1;
//	if (is_same(*cmd, "exit"))
//		exit(0);
//	else if (is_same(*cmd, "cd"))
//		sh_cd(cmd, envs, wstatus);
//	else if (is_same(*cmd, "export") && *(cmd + 1))
//		sh_export(cmd + 1, envs);
//	else if (is_same(*cmd, "unset"))
//		sh_unset(cmd + 1, envs);
//	else
//		ret = 0;
//	return (ret);
//}

void	fork_cmd_switch(char **cmd, t_list *envs, char **envp, int fd)
{
	if (is_same(*cmd, "echo"))
		sh_echo(cmd + 1, fd);
	else if (is_same(*cmd, "pwd"))
		sh_pwd(cmd, fd);
	else if (is_same(*cmd, "env"))
		sh_env(cmd, envs, fd);
	else if (is_same(*cmd, "ls"))
		sh_ls(fd);
	else if (is_same(*cmd, "clear"))
		sh_clear(cmd, fd);
	else if (ft_strncmp(*cmd, "./", 2) == 0)
		sh_exec(cmd, envp);
	else
	{
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		exit(1);
	}
}
