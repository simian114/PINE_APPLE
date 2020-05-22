/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:39:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/22 22:13:59 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
