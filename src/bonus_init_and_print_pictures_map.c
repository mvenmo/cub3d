/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_and_print_pictures_map.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:00:07 by botilia           #+#    #+#             */
/*   Updated: 2022/07/15 12:39:31 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bonus_map_init_pictures(t_game *game)
{
	int	x;
	int	y;

	game->npc_img.img = mlx_xpm_file_to_image(game->mlx,
			"bonus_map/red.xpm", &x, &y);
	game->npc_img.addr = mlx_get_data_addr(game->npc_img.img,
			&game->npc_img.bits_per_pixel, &game->npc_img.line_length,
			&game->npc_img.endian);
	game->wall_img.img = mlx_xpm_file_to_image(game->mlx,
			"bonus_map/black.xpm", &x, &y);
	game->wall_img.addr = mlx_get_data_addr(game->wall_img.img,
			&game->wall_img.bits_per_pixel, &game->wall_img.line_length,
			&game->wall_img.endian);
}

void	print_bonus_map_pictures(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->only_map_h)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img.img, x * MAP_SCALE, y * MAP_SCALE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->npc_img.img, (int)game->pos_x * MAP_SCALE,
		(int)game->pos_y * MAP_SCALE);
}
