/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_map2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:15:34 by botilia           #+#    #+#             */
/*   Updated: 2022/07/12 15:05:25 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pruning_map(t_game *game, int ps)
{
	int	i;
	int	count;

	count = game->only_map_h;
	i = -1;
	game->only_map_h = 0;
	while (++i < count)
	{
		if (game->trim_map[ps][0] == '1')
			game->only_map_h++;
		ps++;
	}
}

void	inside_check_border2(t_game *game, int i, int j)
{
	j--;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			error_exit(game, 10);
		j++;
	}
}

void	check_border2(t_game *game)
{
	int	i;
	int	j;
	int	len_this_line;
	int	len_next_line;

	i = -1;
	while (++i < game->only_map_h - 1)
	{
		len_this_line = ft_strlen(game->map[i]);
		len_next_line = ft_strlen(game->map[i + 1]);
		if (len_this_line > len_next_line)
		{
			j = len_next_line;
			inside_check_border2(game, i, j);
		}
		else if (len_this_line < len_next_line)
		{
			j = len_this_line;
			inside_check_border2(game, i + 1, j);
		}
	}
}

void	get_max_lenght(t_game *game)
{
	int	i;
	int	len;

	i = -1;
	game->map_l = 0;
	while (++i < game->only_map_h)
	{
		len = ft_strlen(game->map[i]);
		if (game->map_l < len)
			game->map_l = len;
	}
	if (game->map_l < 3 || game->only_map_h < 3)
		error_exit(game, 7);
}
