/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:29:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/20 14:12:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

int				g_core;

/*
** builtins
*/
void			sh_cd(char **args, t_list *envs, int *wstatus);
void			sh_clear(char **args, int fd);
void			sh_echo(char **args, int fd);
void			sh_env(char **args, t_list *envs, int fd);
void			sh_exec(char **args, char **envp);
void			sh_export(char **args, t_list *envs);
void			sh_ls(int fd);
void			sh_pwd(char **args, int fd);
void			sh_unset(char **args, t_list *envs);

/*
** check redirection.c
*/
int				check_redirection(char **cmd, int *fd_file);

/*
** cmd_switch.c
*/
void			fork_cmd_switch(char **cmd, t_list *envs, char **envp, int fd);
int				cmd_switch(char **cmd, t_list *envs, int *wstatus);

/*
** convert_arg.c
*/
char			*convert_arg_1(char **command, char **ret, int *quote);
char			*convert_arg_1_1(char **command, char **ret);
char			*convert_arg_1_2(char **command, char **ret);
char			*convert_arg_1_3(char **command, char **ret);
char			**convert_arg_2(char **command, t_list *envs,
								int *quote, char **ret);

/*
** exec_line.c
*/
void			exec_line(char *line, t_list *envs, char **envp, int *wstatus);

/*
** get_args.c
*/
char			**get_args(char *command, t_list *envs);
int				key_len(char *str);

/*
** pipe.c
*/
char			***pipe_split(char **args);

/*
** print_art.c
*/
void			print_art(void);

/*
** print_commandline.c
*/
int				print_commandline(void);

/*
** semicolon.c
*/
char			**semicolon_split(char *line);

/*
** signal.c
*/
void			sigint_handle();
void			sigquit_handle();

/*
** store_status.c
*/
void			store_status(t_list *envs, int *wstatus);

/*
** util_env.c
*/
t_list			*make_envs(char **envp);
char			*get_key(char *str);
char			*get_value(char *str);
char			*find_value(t_list *envs, char *key);

/*
** util_free.c
*/
void			free_double_char(char ***str);
void			free_triple_char(char ****cmds);
void			del(void *content);

/*
** util.c
*/
int				get_line(char **line);
int				ft_max(int a, int b);
int				is_same(char *a, char *b);
int				get_argc(char **args);
char			*char_to_str(char c);

#endif
