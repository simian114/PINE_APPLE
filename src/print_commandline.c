/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:10:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/24 04:38:03 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			print_commandline(void)
{
	char	*cwd;
	int		refresh;

	if (g_option == 1)
	{
		g_option = 2;
		return (1);
	}
	cwd = getcwd(0, 1024);
	ft_putstr_fd("\033[36m\033[3m\033[01m", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd("\033[35m", 1);
	ft_putstr_fd(" >> ", 1);
	ft_putstr_fd("\033[0m", 1);
	if (g_option == 2)
	{
		g_option = 0;
		refresh = ft_strlen(ft_strrchr(cwd, '/') + 1) + 5;
		ft_putstr_fd("\e[", 1);
		ft_putnbr_fd(refresh, 1);
		ft_putstr_fd("G\e[0K", 1);
	}
	free(cwd);
	return (1);
}
