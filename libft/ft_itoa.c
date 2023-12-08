/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:47:48 by botilia           #+#    #+#             */
/*   Updated: 2021/10/15 20:16:34 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	fnsize(int n)
{
	int	sizemol;

	if (n > 0)
		sizemol = 0;
	else
		sizemol = 1;
	while (n)
	{
		n /= 10;
		sizemol++;
	}
	return (sizemol);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*str;

	i = fnsize(n);
	j = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (j < 0)
	{
		j = j * (-1);
		str[0] = '-';
	}
	if (j == 0)
		str[0] = '0';
	str[i] = '\0';
	while (j)
	{
		str[i - 1] = ((j % 10) + 48);
		j /= 10;
		i--;
	}
	return (str);
}
