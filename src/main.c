/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 23:25:02 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;

	if (!argc && argv)
		exit(1);
	print_art();
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle); // 컨트롤\는 안먹힘.
	// 컨트롤d눌러도 exit되게 추가해야.
	envs = make_envs(envp);
	print_commandline();
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "exit", 4))
			exit(0);
		exec_command(line, envs, envp);
		print_commandline();
		free(line);
	}
	free(line);
}
