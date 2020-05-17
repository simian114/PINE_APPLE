/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:32:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 08:22:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*malloc_or_free(char **ret, int i, int wl)
{
	char	*s;

	s = (char *)malloc(wl + 1);
	if (!s)
	{
		while (i >= 0)
			free(ret[i--]);
		free(ret);
	}
	return (s);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		wc;
	int		wl;
	int		i;
	int		j;

	if (!s)
		return (0);
	wc = word_count(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (0);
	ret[wc] = 0;
	i = -1;
	while (++i < wc)
	{
		j = 0;
		while (*s == c)
			s++;
		wl = word_len(s, c);
		ret[i] = malloc_or_free(ret, i, wl);
		ret[i][wl] = '\0';
		while (j < wl)
			ret[i][j++] = *(s++);
	}
	return (ret);
}
