/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:44:18 by sanam             #+#    #+#             */
/*   Updated: 2020/05/22 21:21:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_arg_1(char **command, char **ret, int *quote)
{
	if (*quote == 0 && **command == '>')
		return (convert_arg_1_1(command, ret));
	else if (*quote == 0 && **command == '<')
		return (convert_arg_1_2(command, ret));
	else if (*quote == 0 && **command == '|')
		return (convert_arg_1_3(command, ret));
	return (*ret);
}

char	*convert_arg_1_1(char **command, char **ret)
{
	int		len;

	len = 0;
	while (*(*command + len) == '>')
		len++;
	free(*ret);
	if (len < 3)
		*ret = char_to_str(len * -1);
	else
		*ret = char_to_str(-10);
	*command += len;
	return (*ret);
}

char	*convert_arg_1_2(char **command, char **ret)
{
	int		len;

	len = 0;
	while (*(*command + len) == '<')
		len++;
	free(*ret);
	if (len == 1)
		*ret = char_to_str(-3);
	else
		*ret = char_to_str(-11);
	*command += len;
	return (*ret);
}

char	*convert_arg_1_3(char **command, char **ret)
{
	int		len;

	len = 0;
	while (*(*command + len) == '|')
		len++;
	free(*ret);
	if (len == 1)
		*ret = char_to_str(-4);
	else
		*ret = char_to_str(-12);
	*command += len;
	return (*ret);
}

char	**convert_arg_2(char **command, t_list *envs,
							int *quote, char **ret)
{
	char	*key;

	if (*quote == 0 && (**command == '\'' || **command == '\"'))
		*quote += **command;
	else if (*quote != 0 && **command == *quote)
		*quote -= **command;
	else if (*quote != '\'' && **command == '$')
	{
		(*command)++;
		key = ft_substr(*command, 0, key_len(*command));
		*ret = ft_strjoin_s1free(*ret, find_value(envs, key));
		*command += ft_strlen(key) - 1;
	}
	else if (**command < -20)
		*ret = ft_strjoin_free(*ret, char_to_str(**command * -1));
	else
		*ret = ft_strjoin_free(*ret, char_to_str(**command));
	(*command)++;
	return (command);
}
