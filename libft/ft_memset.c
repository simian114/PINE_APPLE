/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:48:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 00:48:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ret[i] = c;
		i++;
	}
	return (s);
}
