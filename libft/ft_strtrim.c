/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:38:48 by mvenmo            #+#    #+#             */
/*   Updated: 2021/10/16 09:54:25 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;	
	size_t			e;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	e = ft_strlen(s1);
	while (e > i + 1 && ft_strchr(set, s1[e]))
		e--;
	return (ft_substr(s1, i, e - i + 1));
}
