/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:20:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/23 23:56:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	path_len(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str && *str != ':')
	{
		len++;
		str++;
	}
	return (len);
}

static void	exec_path(t_list *envs, char **args, char **envp)
{
	char	*env_path;
	char	*env_path_adr;
	char	*path;
	int		ret;

	env_path = ft_strdup(find_value(envs, "PATH"));
	env_path_adr = env_path;
	while (*env_path)
	{
		if (*env_path == ':')
			env_path++;
		path = ft_substr(env_path, 0, path_len(env_path));
		env_path += path_len(env_path);
		path = ft_strjoin_free(path, char_to_str('/'));
		path = ft_strjoin_s1free(path, *args);
		ret = execve(path, args, envp);
		free(path);
		if (ret >= 0)
			exit(0);
	}
	free(env_path_adr);
}

void		sh_exec(char **args, char **envp, t_list *envs)
{
	int		ret;

	if (ft_strncmp(*args, "/", 1) == 0 || ft_strncmp(*args, ".", 1) == 0)
	{
		ret = execve(*args, args, envp);
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
			exec_path(envs, args, envp);
		ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(*args, 2);
		exit(1);
	}
}
