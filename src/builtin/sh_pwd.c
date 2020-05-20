/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:17:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 11:07:54 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_pwd(char **args, int fd)
{
	int		argc;
	char	*cwd;

	argc = get_argc(args);
	if (argc > 1)
	{
		ft_putstr_fd("pwd: ", 2);
		ft_putendl_fd("too many arguments", 2);
		exit(1);
	}
	cwd = getcwd(0, 1024);
	ft_putendl_fd(cwd, fd);
	free(cwd);
	exit(0);
}
