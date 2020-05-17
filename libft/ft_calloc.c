/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:03:07 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/04 04:54:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(size * num);
	if (!ret)
		return (0);
	i = 0;
	while (i < size * num)
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}
