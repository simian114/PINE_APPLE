/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:55:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 20:28:58 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int args_count(char *command)
{
	int count;
	int quote;

	count = 0;
	quote = 0;
	while (*command)
	{
		if (quote == 0 && (*command == '\'' || *command == '\"'))
			quote += *command;
		else if (quote != 0 && *command == quote)
			quote -= *command;
		if (quote == 0 &&
			(*command != ' ' && *command != '>' && *command != '|') &&
			(*(command + 1) == ' ' || !*(command + 1) ||
			*(command + 1) == '>' || *(command + 1) == '|'))
			count++;
		else if (quote == 0 && *command == '>')
		{
			count++;
			while (*command == '>')
				command++;
			command--;
		}
		else if (quote == 0 && *command == '|') // 잘 될까?
		{
			count++;
			while (*command == '|')
				command++;
			command--;
		}
		command++;
	}
	return (count);
}

static int key_len(char *str)
{
	int len;

	len = 0;
	while (*str && !(*str == ' ' || *str == '\'' || *str == '\"'))
	{
		str++;
		len++;
	}
	return (len);
}

static char *convert_arg(char **command, t_list *envs)
{
	char *ret_tmp;
	char *ret;
	int quote;
	char *key;
	char *to_add;
	int	len;

	quote = 0;
	ret = ft_strdup("");
	ret_tmp = ret;
	while (**command)
	{
		if (quote == 0 && **command == '>')
		{
			len = 0;
			while (*(*command + len) == '>')
				len++;
			free(ret);
			// ret = ft_substr(*command, 0, len);
			if (len == 1)
				ret = char_to_str(-1);
			else if (len == 2)
				ret = char_to_str(-2);
			else
			{
				ft_putstr_fd("error in >.\n", 2); //임시
				return (0);
			}
			*command += len;
			return (ret);
		}
		else if (quote == 0 && **command == '<')
		{
			len = 0;
			while (*(*command + len) == '<')
				len++;
			free(ret);
			// ret = ft_substr(*command, 0, len);
			if (len == 1)
				ret = char_to_str(-3);
			else
			{
				ft_putstr_fd("error in <.\n", 2); //임시
				return (0);
			}
			*command += len;
			return (ret);
		}
		else if (quote == 0 && **command == '|')
		{
			len = 0;
			while (*(*command + len) == '|')
				len++;
			free(ret);
			// ret = ft_substr(*command, 0, len);
			if (len == 1)
				ret = char_to_str(-4);
			else
			{
				ft_putstr_fd("error in |.\n", 2);
				return (0);
			}
			*command += len;
			return (ret);
		}
		if (quote == 0 && (**command == '\'' || **command == '\"'))
			quote += **command;
		else if (quote != 0 && **command == quote)
			quote -= **command;
		else if (quote != '\'' && **command == '$') // 이부분
		{
			(*command)++;
			key = ft_substr(*command, 0, key_len(*command));
			// printf("<%s>\n", key);
			to_add = find_value(envs, key);
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(ret);
			ret = ret_tmp;
			*command += ft_strlen(key) - 1;
		}
		else
		{
			to_add = char_to_str(**command);
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(to_add);
			free(ret);
			ret = ret_tmp;
		}
		(*command)++;
		if (quote == 0 && (**command == ' ' || **command == '>' || **command == '|'))
			break;
	}
	return (ret);
}

char **get_args(char *command, t_list *envs)
{
	int count;
	char **args;
	int i;

	count = args_count(command);
	// printf("%d\n", count);
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
