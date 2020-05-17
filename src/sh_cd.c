/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 03:11:11 by gmoon            ###   ########.fr       */
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
			ft_putstr_fd("cd: no such file or directory: ", 1); // 에러로 수정 필요.
			ft_putendl_fd(home, 1);
		}
	}
	else if (argc == 2)
	{
		if (chdir(args[1]) == -1)
		{
			// ft_putstr_fd("moong_shell: ", 2); // 이런식으로 바꿔야됨.
			// ft_putendl_fd(strerror(errno), 1);
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putendl_fd(args[1], 1);
		}
	}
	else
		ft_putendl_fd("cd: too many arguments", 2);
}
