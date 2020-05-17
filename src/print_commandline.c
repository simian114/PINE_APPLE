/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:10:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 22:38:23 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_commandline()
{
	char	*cwd;

	cwd = getcwd(0, 1024); // 1024가 의미하는 것이 뭐지?
	// ft_putstr_fd("(", 1);
	ft_putstr_fd("\033[36m\033[3m\033[01m", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd("\033[35m", 1);
	ft_putstr_fd(" >> ", 1);
	ft_putstr_fd("\033[0m", 1);
	free(cwd);
}
