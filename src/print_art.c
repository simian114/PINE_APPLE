/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <sanam@studenr.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:11:05 by sanam             #+#    #+#             */
/*   Updated: 2020/05/19 00:05:27 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_art(void)
{
	int		fd;
	char	*line;

	fd = open("config/art", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr_fd("\033[36m", 1);
		ft_putendl_fd(line, STDOUT_FILENO);
		free(line);
	}
	close(fd);
	free(line);
	ft_putstr_fd("\033[0m", 1);
}
