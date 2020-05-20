/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:49:26 by sanam             #+#    #+#             */
/*   Updated: 2020/05/21 07:13:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirection_error(int ret)
{
	char	temp[2];

	ft_bzero(temp, 2);
	if (ret == -10)
		*temp = '>';
	else if (ret == -11)
		*temp = '<';
	else
		*temp = '|';
	ft_putstr_fd("\033[3m\033[31mPINE_APPLE:\033[0m ", 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putstr_fd(temp, 2);
	ft_putendl_fd("'", 2);
	exit(-1);
}

int			check_redirection(char **cmd, int *fd_file)
{
	int		ret;

	ret = 0;
	while (*cmd)
	{
		if (**cmd < 0)
		{
			ret = **cmd;
			break ;
		}
		cmd++;
	}
	if (ret == -1)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (ret == -2)
		*fd_file = open(*(cmd + 1), O_WRONLY | O_CREAT | O_APPEND, 0744);
	else if (ret == -3)
		*fd_file = open(*(cmd + 1), O_RDONLY);
	else if (ret == -10 || ret == -11 || ret == -12)
		redirection_error(ret);
	else
		*fd_file = 1;
	return (ret);
}
