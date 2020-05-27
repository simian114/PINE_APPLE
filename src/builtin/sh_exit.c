/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:38:45 by sanam             #+#    #+#             */
/*   Updated: 2020/05/27 16:52:48 by gmoon            ###   ########.fr       */
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

int			sh_exit(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	ft_putendl_fd("exit", 2);
	if (i == 1)
		exit(0);
	else if (i == 2 && check_numeric(cmd[1]) == 0)
		exit(ft_atoi(cmd[1]));
	else if (i > 2 && check_numeric(cmd[1]) == 0)
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
	else
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", 2);
		exit(2);
	}
	return (1);
}
