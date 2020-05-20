/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:43:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 11:08:20 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_unset(char **args, t_list *envs)
{
	t_list *curr;
	t_list *next;

	while (*args)
	{
		curr = envs;
		while (curr->next)
		{
			next = curr->next;
			if (is_same(((t_env *)next->content)->key, *args))
			{
				curr->next = next->next;
				free(((t_env *)next->content)->key);
				free(((t_env *)next->content)->value);
				free(next->content);
				free(next);
				break ;
			}
			curr = next;
		}
		args++;
	}
}
