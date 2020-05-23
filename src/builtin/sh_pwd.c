/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:17:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/23 23:54:57 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_pwd(char **args, int fd)
{
	char	*cwd;

	if (!args)
		exit(1);
	cwd = getcwd(0, 1024);
	ft_putendl_fd(cwd, fd);
	free(cwd);
	exit(0);
}
