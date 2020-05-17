/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:35:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/04 04:24:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ret;
	int		i;

	size = ft_strlen(s);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (0);
	ret[size] = '\0';
	i = 0;
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
