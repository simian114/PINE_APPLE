/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 00:44:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// static int echo_count(char *str)
// {
// 	int wc;
// 	int flag;

// 	wc = 0;
// 	flag = 0;
// 	while (*str)
// 	{
// 		if (flag == 0 && (*str == '\'' || *str == '\"'))
// 			flag += *str;
// 		else if (flag != 0 && *str == flag)
// 			flag -= *str;
// 		if (flag == 0 && *str != ' ' && (*(str + 1) == ' ' || !*(str + 1)))
// 			wc++;
// 		str++;
// 	}
// 	return (wc);
// }

// static void echo_print(char **str, int fd)
// {
// 	int flag;

// 	flag = 0;
// 	while (**str)
// 	{
// 		if (flag == 0 && (**str == '\'' || **str == '\"'))
// 			flag += **str;
// 		else if (flag != 0 && **str == flag)
// 			flag -= **str;
// 		if (flag == 0 && (**str == ' ' || !**str))
// 			return ;
// 		if (flag == 0 && !(**str == '\'' || **str == '\"'))
// 			ft_putchar_fd(**str, fd);
// 		else if (flag != 0 && **str != flag)
// 			ft_putchar_fd(**str, fd);
// 		(*str)++;
// 	}
// 	return ;
// }

// static void echo_process(char *str, int fd, int option_n)
// {
// 	int wc;
// 	int i;

// 	if (option_n == -1)
// 		return ;
// 	wc = echo_count(str);
// 	if (wc == 0)
// 	{
// 		ft_putchar_fd('\n', fd);
// 		return ;
// 	}
// 	i = -1;
// 	while (++i < wc)
// 	{
// 		while (*str == ' ')
// 			str++;
// 		echo_print(&str, fd);
// 		if (i != wc - 1)
// 			ft_putchar_fd(' ', fd);
// 		else if (option_n == 0)
// 			ft_putchar_fd('\n', fd);
// 	}
// 	return ;
// }

// void sh_echo(char *command, t_list *envs, int fd)
// {
// 	char *str;
// 	char *str_tmp;
// 	int option_n;

// 	if (!envs)
// 		return ;
// 	str = command + 4;
// 	str_tmp = str;
// 	option_n = 0;
// 	while (*str_tmp == ' ' && *str_tmp)
// 		str_tmp++;
// 	if (ft_strncmp(str_tmp, "-n ", 3) == 0)
// 	{
// 		option_n = 1;
// 		str_tmp += 3;
// 	}
// 	echo_process(str_tmp, fd, option_n);
// 	if (option_n == 1 && fd == 1)
// 		ft_putstr_fd("%\n", 1);
// }

void sh_echo(char **args, int fd)
{
	int option_n;
	int argc;
	int i;

	option_n = 0;
	argc = get_argc(args);
	if (argc == 0)
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	if (is_same(args[0], "-n"))
	{
		option_n = 1;
		args++;
		argc--;
	}
	i = -1;
	while (++i < argc)
	{
		ft_putstr_fd(args[i], fd);
		if (i != argc - 1)
			ft_putchar_fd(' ', fd);
		else if (i == argc - 1 && option_n == 0)
			ft_putchar_fd('\n', fd);
		else if (i == argc - 1 && option_n == 1 && fd == 1)
			ft_putchar_fd('%', 1);
	}
}

// "" 남아있게 바꿔서, 이거 변환해서 echo하도록 수정해야함.