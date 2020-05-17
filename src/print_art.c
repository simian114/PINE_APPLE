/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <sanam@studenr.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:11:05 by sanam             #+#    #+#             */
/*   Updated: 2020/05/17 23:14:36 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_art(void)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open("config/art", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		temp = line;
		line = ft_strjoin("\033[36m\033[36m", line);
		ft_putendl_fd(line, STDOUT_FILENO);
		free(temp);
		free(line);
	}
	ft_putstr_fd("\033[0m", 1);
}
