/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 10:46:50 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_env(char **args, t_list *envs, int fd)
{
	int		argc;
	t_list	*curr;

	if ((argc = get_argc(args)) > 1)
	{
		ft_putendl_fd("env: too many arguments", 2);
		exit(1);
	}
	curr = envs;
	while (curr)
	{
		if (ft_strncmp(((t_env *)curr->content)->key, "?",
			ft_strlen(((t_env *)curr->content)->key)))
		{
			ft_putstr_fd(((t_env *)curr->content)->key, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(((t_env *)curr->content)->value, fd);
		}
		curr = curr->next;
	}
	exit(0);
}
