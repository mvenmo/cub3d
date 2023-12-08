/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:51:27 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 19:59:21 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t		a;
	size_t		j;
	size_t		y;

	a = 0;
	j = 0;
	y = 0;
	while (dst[j] && j < dstsize)
		j++;
	a = j;
	while (src[y] && j + 1 < dstsize)
	{
		dst[j] = src[y];
		j++;
		y++;
	}
	if (a < dstsize)
		dst[j] = '\0';
	return (a + ft_strlen(src));
}
