/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:57:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 08:21:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*ret;

	if (!s1 || !set)
		return (0);
	i = -1;
	start = -1;
	end = -1;
	while (s1[++i])
		if (is_set(s1[i], set) == 0 && start == -1)
			start = i;
	while (s1[--i])
		if (is_set(s1[i], set) == 0 && end == -1)
			end = i;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		return (0);
	ret[end - start + 1] = '\0';
	i = 0;
	while (start <= end)
		ret[i++] = s1[start++];
	return (ret);
}
