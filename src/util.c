/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:39:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 11:12:33 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_line(char **line)
{
	char	buf[2];
	char	*temp;

	ft_bzero(buf, 2);
	*line = ft_strdup("");
	while (*buf != '\n')
	{
		while (read(0, buf, 1) && *buf != '\n')
		{
			temp = *line;
			*line = ft_strjoin(*line, buf);
			free(temp);
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
