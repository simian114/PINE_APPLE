/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 05:47:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_cd(char **args, t_list *envs)
{
	int		argc;
	char	*home;

	argc = get_argc(args);
	if (argc == 1)
	{
		home = find_value(envs, "HOME");
		if (chdir(home) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(home, 2);
		}
	}
	else if (argc == 2)
	{
		if (chdir(args[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(args[1], 2);
		}
	}
	else
		ft_putendl_fd("cd: too many arguments", 2);
}
