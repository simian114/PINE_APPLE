/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 02:43:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_line(char **line)
{
	char	buf[2];
	char	*temp;

	ft_bzero(buf, 2);
	*line = ft_strdup("");
	while (*buf != '\n')
	{
		while (read(0, buf, 1) && *buf != '\n')
		{
			temp = *line;
			*line = ft_strjoin(*line, buf);
			free(temp);
		}
		if (ft_strlen(*line) == 0 && *buf != '\n')
			return(0);
	}
	return (1);
}

void del(void *content)
{
	t_env *temp;

	temp = (t_env *)content;
	free(temp->key);
	free(temp->value);
	free(temp);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;

	if (!argc && argv)
		exit(1);
	print_art();
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
	envs = make_envs(envp);
	while (print_commandline() && get_line(&line))
		exec_line(line, envs, envp);
	free(line);
	ft_lstclear(&envs, del);
}
