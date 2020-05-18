/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:39:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/18 22:42:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int is_same(char *a, char *b)
{
	if (ft_strncmp(a, b, ft_max(ft_strlen(a), ft_strlen(b))) == 0)
		return (1);
	return (0);
}

int is_command(char *a, char *b)
{
	char	*b_space;
	int		ret;

	b_space = ft_strjoin(b, " ");
	if (is_same(a, b))
		ret = 1;
	else if (ft_strncmp(a, b_space, ft_strlen(b_space)) == 0)
		ret = 1;
	else
		ret = 0;
	free(b_space);
	return (ret);
}

void free_double_char(char ***str)
{
	char **str_adr;

	str_adr = *str;
	while (**str)
	{
		free(**str);
		(*str)++;
	}
	free(str_adr);
}

int get_argc(char **args)
{
	int count;

	count = 0;
	while (*args)
	{
		if (**args < 0)
			break ;
		count++;
		args++;
	}
	return (count);
}

char *char_to_str(char c)
{
	char *ret;

	ret = (char *)malloc(2);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

void free_triple_char(char ****cmds)
{
	char ***triple_adr;
	char **double_adr;

	triple_adr = *cmds;
	while (**cmds)
	{
		double_adr = **cmds;
		while (***cmds)
		{
			free(***cmds);
			(**cmds)++;
		}
		(*cmds)++;
		free(double_adr);
	}
	free(triple_adr);
}
