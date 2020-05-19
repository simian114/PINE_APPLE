/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 03:14:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sh_echo(char **args, int fd)
{
	int option_n;
	int argc;
	int i;

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
	i = -1;
	while (++i < argc)
	{
		ft_putstr_fd(args[i], fd);
		if (i != argc - 1)
			ft_putchar_fd(' ', fd);
		else if (i == argc - 1 && option_n == 0)
			ft_putchar_fd('\n', fd);
		// else if (i == argc - 1 && option_n == 1 && fd == 1)
		// 	ft_putstr_fd("\c", 1);
	}
	exit(0);
}
