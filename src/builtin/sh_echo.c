/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/24 03:08:24 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **args, int fd, int option_n)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (args[i + 1])
		{
			ft_putstr_fd(args[i], fd);
			ft_putstr_fd(" ", fd);
		}
		else
		{
			if (option_n == 1)
				ft_putstr_fd(args[i], fd);
			else
				ft_putendl_fd(args[i], fd);
		}
	}
	exit(0);
}

void	sh_echo(char **args, int fd)
{
	int option_n;
	int argc;

	option_n = 0;
	argc = get_argc(args);
	if (argc == 0)
	{
		ft_putchar_fd('\n', fd);
		exit(0);
	}
	if (is_same(*args, "-n"))
	{
		option_n = 1;
		args++;
		argc--;
	}
	echo_print(args, fd, option_n);
}
