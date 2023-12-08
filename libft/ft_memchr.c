/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:21 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 20:05:51 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*r;
	size_t		i;

	r = s;
	i = 0;
	while (i < n)
	{
		if (r[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
