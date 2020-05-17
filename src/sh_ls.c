/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:21:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 21:57:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_ls(int fd)
{
	char			*cwd;
	DIR				*dir;
	int				flag;
	struct dirent	*file;

	cwd = getcwd(0, 1024);
	dir = opendir(cwd);
	flag = 0;
	while ((file = readdir(dir)))
	{
		if (flag != 0)
			ft_putstr_fd("  ", fd);
		if (!is_same(file->d_name, ".") && !is_same(file->d_name, ".."))
		{
			ft_putstr_fd(file->d_name, fd);
			flag = 1;
		}
	}
	ft_putstr_fd("\n", fd);
	closedir(dir);
	free(cwd);
}
