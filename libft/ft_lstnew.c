/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:41:01 by botilia           #+#    #+#             */
/*   Updated: 2021/10/13 11:25:50 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newstr;

	newstr = (t_list *)malloc(sizeof(t_list));
	if (!newstr)
		return (NULL);
	newstr->content = content;
	newstr->next = NULL;
	return (newstr);
}
