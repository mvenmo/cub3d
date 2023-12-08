/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:48:36 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 19:54:59 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*r;
	const char	*u;

	r = s1;
	u = s2;
	i = 0;
	while (i < n)
	{
		if (r[i] != u[i])
			return ((unsigned char)r[i] - (unsigned char)u[i]);
		i++;
	}
	return (0);
}
