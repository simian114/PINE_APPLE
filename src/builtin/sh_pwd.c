/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:17:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 06:52:42 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_pwd(char **args, int fd)
{
	// int		argc;
	char	*cwd;

	if (!args)
		exit(1);
	// argc = get_argc(args);
	// if (argc > 1)
	// {
	// 	ft_putstr_fd("pwd: ", 2);
	// 	ft_putendl_fd("too many arguments", 2);
	// 	exit(1);
	// }
	cwd = getcwd(0, 1024);
	ft_putendl_fd(cwd, fd);
	free(cwd);
	exit(0);
}
