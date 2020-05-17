/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 23:53:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 23:07:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_redirection(char *str, int *command_len)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (flag == 0 && (*str == '\'' || *str == '\"'))
			flag += *str;
		else if (flag != 0 && *str == flag)
			flag -= *str;
		if (flag == 0 && *str == '>' && *(str + 1) == '>' && *(str + 2) == '>')
			return (-1);
		if (flag == 0 && *str == '>' && *(str + 1) == '>')
			return (2);
		else if (flag == 0 && *str == '>' && *(str + 1) != '>')
			return (1);
		str++;
		(*command_len)++;
	}
	return (0);
}

void	redirection_split(char *mover, char **command, int *fd)
{
	int		command_len;
	int		redirection;
	char	*command_tmp;
	char	*filename;

	command_len = 0;
	redirection = check_redirection(mover, &command_len);
	command_tmp = ft_substr(mover, 0, command_len);
	*command = ft_strtrim(command_tmp, " ");
	free(command_tmp);
	if (redirection == 0)
		*fd = 1;
	else if (redirection == -1)
	{
		ft_putendl_fd("moong_shell: parse error near `>'", 1); // 에러 함수로 대체 필요.
		*fd = -1;
	}
	filename = ft_strtrim(mover + command_len + redirection, " "); // filename까지만 trim하자.
	if (redirection == 1)
		*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (redirection == 2)
		*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND , 0744);
	free(filename);
}
