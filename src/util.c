/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:39:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/22 21:01:21 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		escape(char **line, int *quote)
{
	char	buf[3];

	ft_bzero(buf, 3);
	*buf = '\\';
	read(0, buf + 1, 1);
	if (*quote == '\'')
		*line = ft_strjoin_s1free(*line, buf);
	else if (*quote == '\"')
	{
		if (buf[1] == '$' || buf[1] == '`' || buf[1] == '"' || buf[1] == '\\')
		{
			if (buf[1] == '$')
				buf[1] = -20;
			*line = ft_strjoin_s1free(*line, buf + 1);
		}
		else
			*line = ft_strjoin_s1free(*line, buf);
	}
	else
		*line = ft_strjoin_s1free(*line, buf + 1);
	return (1);
}

void	quoteing(int *quote, char buf)
{
	if ((buf == '\'' || buf == '\"') && *quote == 0)
		*quote = buf;
	else if ((buf == '\'' || buf == '\"') && *quote != 0)
		*quote = (*quote == buf) ? 0 : *quote;
}

int		get_line(char **line)
{
	char	buf[2];
	int		quote;

	ft_bzero(buf, 2);
	*line = ft_strdup("");
	quote = 0;
	while (*buf != '\n')
	{
		while (read(0, buf, 1) && *buf != '\n')
		{
			if (*buf == '\'' || *buf == '\"')
				quoteing(&quote, *buf);
			if (*buf == '\\' && escape(line, &quote))
				continue ;
			*line = ft_strjoin_s1free(*line, buf);
		}
		if (ft_strlen(*line) == 0 && *buf != '\n')
			return (0);
	}
	return (1);
}

int		ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int		is_same(char *a, char *b)
{
	if (ft_strncmp(a, b, ft_max(ft_strlen(a), ft_strlen(b))) == 0)
		return (1);
	return (0);
}

int		get_argc(char **args)
{
	int count;

	count = 0;
	while (*args)
	{
		count++;
		args++;
	}
	return (count);
}

char	*char_to_str(char c)
{
	char *ret;

	ret = (char *)malloc(2);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
