/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:15:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 01:24:25 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	pull_buf(char *buf)
{
	gnl_memmove(buf,
				buf + strlen_lf(buf) + 1,
				gnl_strlen(buf) - strlen_lf(buf));
}

static int	is_line_made(char *buf, char **line)
{
	*line = gnl_strjoin(*line, buf);
	if (is_contain_lf(buf) == 1)
	{
		pull_buf(buf);
		return (1);
	}
	return (0);
}

static int	free_and_ret(char **buf, char **line, int ret)
{
	if (ret < 0)
	{
		free(*line);
		*line = 0;
		free(*buf);
		*buf = 0;
		return (-1);
	}
	free(*buf);
	*buf = 0;
	return (0);
}

static int	free_line(char **line)
{
	free(*line);
	*line = 0;
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buf;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	if (buf)
	{
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	else
	{
		if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
			return (free_line(line));
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	return (free_and_ret(&buf, line, ret));
}
