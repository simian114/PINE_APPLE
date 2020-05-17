/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:43:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/16 00:17:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = (s2) ? ft_strlen(s2) : 0;
	ret = (char *)malloc(len1 + len2 + 1);
	if (!ret)
		return (0);
	ret[len1 + len2] = '\0';
	i = 0;
	j = 0;
	while (i < len1)
		ret[i++] = s1[j++];
	j = 0;
	while (i < len1 + len2)
		ret[i++] = s2[j++];
	return (ret);
}
