/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:08:48 by sanam             #+#    #+#             */
/*   Updated: 2020/05/24 03:54:58 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		escape(char **line, int *quote)
{
	char	buf[3];

	ft_bzero(buf, 3);
	*buf = '\\';
	read(0, buf + 1, 1);
	if (buf[1] == '>' || buf[1] == '<' || buf[1] == '|' ||
		buf[1] == '$' || buf[1] == '\"')
		buf[1] *= -1;
	if (*quote == '\'')
		*line = ft_strjoin_s1free(*line, buf);
	else if (*quote == '\"')
	{
		if (buf[1] == -1 * '$' || buf[1] == '`' ||
			buf[1] == -1 * '\"' || buf[1] == '\\')
			*line = ft_strjoin_s1free(*line, buf + 1);
		else
			*line = ft_strjoin_s1free(*line, buf);
	}
	else
		*line = ft_strjoin_s1free(*line, buf + 1);
	return (1);
}

static void		quoteing(int *quote, char buf)
{
	if ((buf == '\'' || buf == '\"') && *quote == 0)
		*quote = buf;
	else if ((buf == '\'' || buf == '\"') && *quote != 0)
		*quote = (*quote == buf) ? 0 : *quote;
}

int				get_line(char **line)
{
	char	buf[2];
	int		quote;

	ft_bzero(buf, 2);
	*line = ft_strdup("");
	quote = 0;
	print_commandline();
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
