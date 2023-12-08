/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:48:48 by botilia           #+#    #+#             */
/*   Updated: 2022/06/29 11:10:03 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*last;

	if (!newl)
		return ;
	if (!*lst)
		*lst = newl;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newl;
		newl->next = NULL;
	}
}
