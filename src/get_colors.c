/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:07:29 by botilia           #+#    #+#             */
/*   Updated: 2022/07/13 08:47:24 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_atoi(t_game *game, char *str)
{
	int		i;
	long	k;

	i = 0;
	k = 0;
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error_exit(game, 5);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += ((int)str[i] - '0');
		i++;
	}
	while (str[i] && str[i] != ',')
	{
		if (str[i] != ' ')
			error_exit(game, 5);
		i++;
	}
	if (k > 255)
		error_exit(game, 5);
	return ((int)k);
}

void	init_color_floor_and_ceiling(t_game *game, char *string, int i)
{
	char	*tmp;
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error_exit(game, 4);
	if (string[1] != ' ')
		error_exit(game, 5);
	tmp = string;
	rgb->r = my_atoi(game, tmp);
	tmp = ft_strchr(tmp, ',');
	rgb->g = my_atoi(game, tmp);
	++tmp;
	tmp = ft_strchr(tmp, ',');
	rgb->b = my_atoi(game, tmp);
	if (i == 0)
		game->color_ceiling = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	else
		game->color_floor = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	free(rgb);
}

int	get_colors(t_game *game, char *string)
{
	if (string[0] == 'C' && game->color_ceiling == -1)
		init_color_floor_and_ceiling(game, string, 0);
	else if (string[0] == 'F' && game->color_floor == -1)
		init_color_floor_and_ceiling(game, string, 1);
	else
		error_exit(game, 5);
	return (1);
}
