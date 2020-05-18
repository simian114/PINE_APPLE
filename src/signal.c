/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 02:19:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/18 12:08:51 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sigint_handle()
{
//	ft_putstr_fd("\n", 1);
//	ft_putendl_fd("SIGINT?", 1);
	ft_putendl_fd("", 1);
	print_commandline();
}

void		sigquit_handle()
{
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("SIGQUIT?", 1);
	print_commandline();
}
