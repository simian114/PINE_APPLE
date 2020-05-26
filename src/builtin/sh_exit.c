/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:38:45 by sanam             #+#    #+#             */
/*   Updated: 2020/05/26 09:15:20 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_numeric(char *cmd)
{
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isdigit((int)cmd[i]))
			return (1);
	}
	return (0);
}
#include <stdio.h>
int			sh_exit(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	ft_putendl_fd("exit", 2);
	if (i == 1)
		exit(0);
	else if (i == 2)
	{
		if (check_numeric(cmd[1]) == 0)
			exit(ft_atoi(cmd[1]));
		else
		{
			ft_putendl_fd("bash: exit: numeric argument required", 2);
			exit(2);
		}
	}
	else
		ft_putendl_fd("bash: exit: too many arguments", 2);
	// if (i == 1)
	// 	exit(0);
	// else if (i > 2)
	// {
	// 	printf("zz?\n");
	// 	if (!check_numeric(cmd[1]))
	// 	{
	// 		printf("test\n");
	// 		ft_putendl_fd("exit\nbash: exit: too many arguments", 2);
	// 		return (1);
	// 	}	
	// 	ft_putstr_fd("exit\nbash: exit: ", 2);
	// 	ft_putstr_fd(cmd[1], 2);
	// 	ft_putendl_fd(": numeric argument required", 2);
	// 	exit(2);
	// }
	// else if (i == 2)
	// {
	// 	if (check_numeric(cmd[1]))
	// 		exit(2);
	// 	else
	// 		exit(ft_atoi(cmd[1]));
	// }
	// exit(i);
	return (1);
}
