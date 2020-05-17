/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 08:25:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 09:32:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *curr;

	if (!lst)
		return (0);
	else if (!(ret = ft_lstnew((*f)(lst->content))))
		return (0);
	curr = ret;
	while (lst)
	{
		curr->next = ft_lstnew((*f)(lst->content));
		if (!curr->next)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (ret);
}
