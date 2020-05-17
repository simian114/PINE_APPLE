/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:42:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 02:57:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_env(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

void		sh_export(char **args, t_list *envs)
{
	t_env	*env;
	t_list	*curr;

	while (*args)
	{
		if (is_valid_env(*args))
		{
			env = (t_env *)malloc(sizeof(t_env));
			env->key = get_key(*args);
			env->value = get_value(*args);
			curr = envs;
			while (curr)
			{
				if (is_same(((t_env *)curr->content)->key, env->key))
				{
					free(((t_env *)curr->content)->value);
					((t_env *)curr->content)->value = env->value;
					free(env->key);
					free(env);
					break ;
				}
				curr = curr->next;
			}
			if (!curr)
				ft_lstadd_back(&envs, ft_lstnew(env));
		}
		args++;
	}
}
