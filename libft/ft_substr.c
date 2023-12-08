/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:41:23 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 20:19:18 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	k = (char *)malloc((len + 1) * sizeof(char));
	if (!k)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			k[j] = s[i];
			j++;
		}
		i++;
	}
	k[j] = '\0';
	return (k);
}
