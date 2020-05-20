/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 10:42:29 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_error(char *s1, char *s2, int flag, int *wstatus)
{
	*wstatus = 1;
	if (flag == 0)
	{
		ft_putstr_fd(s1, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(s2, 2);
	}
	else
		ft_putendl_fd(s1, 2);
	free(s1);
	free(s2);
}

void	sh_cd(char **args, t_list *envs, int *wstatus)
{
	int		argc;
	char	*home;

	*wstatus = 0;
	argc = get_argc(args);
	if (argc == 1)
	{
		home = find_value(envs, "HOME");
		if (chdir(home) == -1)
			cd_error(ft_strjoin("cd: ", strerror(errno)),
			ft_strdup(home), 0, wstatus);
	}
	else if (argc == 2)
	{
		if (chdir(args[1]) == -1)
			cd_error(ft_strjoin("cd: ", strerror(errno)),
			ft_strdup(args[1]), 0, wstatus);
	}
	else if (argc == 3)
		cd_error(ft_strjoin("cd: ", "string not in pwd"),
		ft_strdup(args[1]), 0, wstatus);
	else
		cd_error(ft_strjoin("cd: ", "too many arguments"),
		ft_strdup(""), 1, wstatus);
}
