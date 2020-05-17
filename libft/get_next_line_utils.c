/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:43:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 04:07:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_contain_lf(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int		strlen_lf(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		gnl_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		s1_size;
	int		s2_size;
	int		size;
	char	*ret;
	int		i;

	s1_size = (s1) ? gnl_strlen(s1) : 0;
	s2_size = (s2) ? strlen_lf(s2) : 0;
	size = s1_size + s2_size;
	if (!(ret = (char *)malloc(size + 1)))
		return (0);
	ret[size] = '\0';
	i = -1;
	while (++i < s1_size)
		*(ret + i) = *(s1 + i);
	while (i - s1_size < s2_size)
		*(ret + i++) = *(s2++);
	if (s1)
		free(s1);
	return (ret);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest <= src)
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	return (dest);
}
