/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:37:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/08 06:52:23 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;
	size_t	i;
	size_t	j;

	little_size = ft_strlen(little);
	if (little_size > len)
		return (0);
	if (little_size == 0)
		return ((char *)big);
	i = -1;
	while (++i < len && big[i])
	{
		j = 0;
		if (little[j] == big[i])
			while (j < little_size && j + i < len)
			{
				if (little[j] != big[i + j])
					break ;
				else
					j++;
				if (j == little_size)
					return ((char *)&big[i]);
			}
	}
	return (0);
}
