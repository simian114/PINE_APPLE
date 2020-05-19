/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <sanam@studenr.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:06:41 by sanam             #+#    #+#             */
/*   Updated: 2020/05/19 17:48:34 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		store_status(t_list *envs, int *wstatus)
{
	char	*status;
	char	*str;
	char	*args[2];

	status = ft_itoa(*wstatus);
	str = ft_strjoin("?=", status);
	args[0] = ft_strdup(str);
	args[1] = NULL;
	sh_export(args, envs);
	free(args[0]);
	free(status);
	free(str);
}
