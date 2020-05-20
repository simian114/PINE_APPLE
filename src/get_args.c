/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:55:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 14:13:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	args_count(char *c, int *count)
{
	int		quote;
	char	temp;

	quote = 0;
	while (*c)
	{
		if (quote == 0 && (*c == '\'' || *c == '\"'))
			quote += *c;
		else if (quote != 0 && *c == quote)
			quote -= *c;
		if (quote == 0 && (*c != ' ' && *c != '>' && *c != '|' && *c != '<') &&
			(*(c + 1) == ' ' || !*(c + 1) ||
			*(c + 1) == '>' || *(c + 1) == '|' || *(c + 1) == '<'))
			*count += 1;
		else if (quote == 0 && (*c == '>' || *c == '|' || *c == '<'))
		{
			temp = *c;
			*count += 1;
			while (*c == temp)
				c++;
			c--;
		}
		c++;
	}
	return (*count);
}

int			key_len(char *str)
{
	int		len;

	len = 0;
	while (*str &&
		!(*str == ' ' || *str == '\'' || *str == '\"' ||
		*str == '<' || *str == '>'))
	{
		str++;
		len++;
	}
	return (len);
}

static char	*convert_arg(char **command, t_list *envs)
{
	int		quote;
	char	*ret;

	quote = 0;
	ret = ft_strdup("");
	while (**command)
	{
		if (quote == 0 && (**command == '>' ||
			**command == '<' || **command == '|'))
		{
			ret = convert_arg_1(command, &ret, &quote);
			return (ret);
		}
		command = convert_arg_2(command, envs, &quote, &ret);
		if (quote == 0 && (**command == ' ' || **command == '>'
			|| **command == '|' || **command == '<'))
			break ;
	}
	return (ret);
}

char		**get_args(char *command, t_list *envs)
{
	int		i;
	int		count;
	char	**args;

	count = 0;
	count = args_count(command, &count);
	args = (char **)malloc(sizeof(char *) * (count + 1));
	args[count] = 0;
	i = -1;
	while (++i < count)
	{
		while (*command == ' ' && *command)
			command++;
		args[i] = convert_arg(&command, envs);
	}
	return (args);
}
