/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:10:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/21 15:19:56 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			print_commandline(void)
{
	char	*cwd;

	if (g_intt == 1)
	{
		g_intt = 0;
		return (1);
	}
	cwd = getcwd(0, 1024);
	ft_putstr_fd("\033[36m\033[3m\033[01m", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd("\033[35m", 1);
	ft_putstr_fd(" >> ", 1);
	ft_putstr_fd("\033[0m", 1);
	free(cwd);
	return (1);
}
