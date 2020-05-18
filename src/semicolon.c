/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 23:52:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 05:46:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	command_count(char *line)
{
	int	count;
	int	quote;

	count = 1;
	quote = 0;
	while (*line)
	{
		if (quote == 0 && (*line == '\'' || *line == '\"'))
			quote += *line;
		else if (quote != 0 && (*line == quote))
			quote -= *line;
		if (quote == 0 && *line == ';')
			count++;
		line++;
	}
	return (count);
}

static int	command_len(char *line)
{
	int	len;
	int	quote;

	len = 0;
	quote = 0;
	while (*line)
	{
		if (quote == 0 && (*line == '\'' || *line == '\"'))
			quote += *line;
		else if (quote != 0 && (*line == quote))
			quote -= *line;
		if (quote == 0 && *line == ';')
			break ;
		len++;
		line++;
	}
	return (len);
}

char		**semicolon_split(char *line)
{
	char	**commands;
	int		count;
	int		i;
	int		len;

	count = command_count(line);
	commands = (char **)malloc(sizeof(char *) * (count + 1));
	commands[count] = 0;
	i = -1;
	while (++i < count)
	{
		len = command_len(line);
		commands[i] = (char *)malloc(len + 1);
		commands[i][len] = '\0';
		ft_memcpy(commands[i], line, len);
		line += len + 1;
	}
	return (commands);
}
