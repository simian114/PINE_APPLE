/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 15:39:59 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;
	int		wstatus;

	if (!argc && argv)
		exit(1);
	print_art();
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
	envs = make_envs(envp);
	while ((print_commandline() && get_line(&line)) || (wstatus = 0))
		exec_line(line, envs, envp, &wstatus);
	free(line);
	ft_lstclear(&envs, del);
}
