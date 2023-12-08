/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:11:32 by botilia           #+#    #+#             */
/*   Updated: 2021/10/16 12:43:30 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;

	if (!*lst)
		return ;
	while (*lst)
	{
		first = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = first;
	}
}
