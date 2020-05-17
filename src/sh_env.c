/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 21:57:10 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sh_env(t_list *envs, int fd)
{
	t_list *curr;

	curr = envs;
	while (curr)
	{
		ft_putstr_fd(((t_env *)curr->content)->key, fd);
		ft_putstr_fd("=", fd);
		ft_putendl_fd(((t_env *)curr->content)->value, fd);
		curr = curr->next;
	}
}
