/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:13:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/19 01:13:21 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1000

int		is_contain_lf(char *buf);
int		strlen_lf(char *str);
int		gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_memmove(void *dest, const void *src, size_t n);
int		get_next_line(int fd, char **line);

#endif
