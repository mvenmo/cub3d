/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:42:28 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 19:55:33 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*a;
	const char	*b;
	size_t		j;

	a = dst;
	b = src;
	j = 0;
	if (b > a)
	{
		while (j < len)
		{
			a[j] = b[j];
			j++;
		}
	}
	if (b < a)
	{
		while (len > 0)
		{
			a[len - 1] = b [len - 1];
			len--;
		}
	}
	return (a);
}
