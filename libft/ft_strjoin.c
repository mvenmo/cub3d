/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:42:41 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 20:18:41 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		j;
	size_t		k;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[k] && k < ft_strlen(s1))
	{
		str[k] = s1[k];
		k++;
	}
	while (s2[j] && k < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[k] = s2[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}
