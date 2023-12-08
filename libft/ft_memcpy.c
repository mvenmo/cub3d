/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:19:19 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 20:06:03 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*a;
	const char	*b;
	int			i;
	size_t		j;

	a = dst;
	b = src;
	i = 0;
	j = 0;
	while (j < n && a != b)
	{
		a[i] = b[i];
		j++;
		i++;
	}
	return (a);
}
