/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:55:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/04 04:23:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*ret;
	int		flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = n_size(n);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (0);
	ret[size] = '\0';
	flag = 0;
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	while (size > 0)
	{
		ret[(size--) - 1] = n % 10 + '0';
		n = n / 10;
	}
	if (flag == 1)
		ret[0] = '-';
	return (ret);
}
