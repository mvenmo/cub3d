/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:07:40 by botilia           #+#    #+#             */
/*   Updated: 2021/10/16 17:32:50 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*chek;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	chek = newlist;
	while (lst->next)
	{
		lst = lst->next;
		newlist->next = ft_lstnew((*f)(lst->content));
		if (!newlist->next)
		{
			del(&lst->content);
			free(lst);
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (chek);
}
