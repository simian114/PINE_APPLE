/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:42:45 by sanam             #+#    #+#             */
/*   Updated: 2020/05/19 13:30:37 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_clear(char **args, int fd)
{
	int		argc;

	argc = get_argc(args);
	if (argc > 1)
	{
		ft_putendl_fd("Usage: clear [options]\n", 2);
		ft_putendl_fd("Options:\n-T TERM     use this instead of $TERM", 2);
		ft_putendl_fd("-V          print curses-version", 2);
		ft_putendl_fd("-x          do not try to clear scrollback", 2);
		exit(1);
	}
	write(fd, "\33[H\33[2J", 7);
	exit(0);
}
