/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:44:04 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 11:13:30 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*make_envs(char **envp)
{
	t_list	*envs;
	t_env	*env;

	envs = 0;
	while (*envp)
	{
		env = (t_env *)malloc(sizeof(t_env));
		env->key = get_key(*envp);
		env->value = get_value(*envp);
		ft_lstadd_back(&envs, ft_lstnew(env));
		envp++;
	}
	return (envs);
}

char		*get_key(char *str)
{
	int		len;
	char	*key;

	len = 0;
	while (str[len] != '=')
		len++;
	key = (char *)malloc(len + 1);
	key[len] = '\0';
	key = ft_memcpy(key, str, len);
	return (key);
}

char		*get_value(char *str)
{
	int		len;
	char	*value;

	len = 0;
	while (*str != '=')
		str++;
	str++;
	while (str[len])
		len++;
	value = (char *)malloc(len + 1);
	value[len] = '\0';
	value = ft_memcpy(value, str, len);
	return (value);
}

char		*find_value(t_list *envs, char *key)
{
	t_list	*curr;

	curr = envs;
	while (curr)
	{
		if (ft_strncmp(((t_env *)curr->content)->key, key,
			ft_max(ft_strlen(((t_env *)curr->content)->key),
			ft_strlen(key))) == 0)
			return (((t_env *)curr->content)->value);
		curr = curr->next;
	}
	return (0);
}
