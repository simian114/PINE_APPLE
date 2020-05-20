/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <sanam@studenr.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:32:01 by sanam             #+#    #+#             */
/*   Updated: 2020/04/28 21:32:12 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_free(char *s1, char *s2)
{
	char		*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
