/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 03:20:31 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 20:25:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int get_cmd_count(char **args)
{
	int ret;

	ret = 0;
	while (*args)
	{
		// if ((**args != '|' && !*(args + 1)) ||
		// 	(**args != '|' && **(args + 1) == '|')) // 아 이거 되게 헷갈리네.
		if ((**args != -4 && !*(args + 1)) ||
			(**args != -4 && **(args + 1) == -4))
			ret++;
		args++;
	}
	return (ret);
}

static int get_args_count(char **args)
{
	int ret;

	ret = 0;
	while (*args)
	{
		// if (**args == '|')
		if (**args == -4)
			break ;
		ret++;
		args++;
	}
	return (ret);
}

char ***pipe_split(char **args)
{
	char ***ret;
	int cmd_count;
	int i;
	int args_count;
	int j;

	cmd_count = get_cmd_count(args);
	ret = (char ***)malloc(sizeof(char **) * (cmd_count + 1));
	ret[cmd_count] = 0;
	i = -1;
	while (++i < cmd_count)
	{
		args_count = get_args_count(args);
		ret[i] = (char **)malloc(sizeof(char *) * (args_count + 1));
		ret[i][args_count] = 0;
		j = -1;
		while (++j < args_count)
		{
			ret[i][j] = ft_strdup(*args);
			args++;
		}
		args++; // 될까?
	}
	return (ret);
}
