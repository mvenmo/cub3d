/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:38:21 by botilia           #+#    #+#             */
/*   Updated: 2022/07/15 12:58:42 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_angle_view(t_game *game, const char c)
{
	if (c == 'E')
		game->view = 0.0f * M_PI;
	else if (c == 'N')
		game->view = 0.5f * M_PI;
	else if (c == 'W')
		game->view = 1.0f * M_PI;
	else if (c == 'S')
		game->view = -0.5f * M_PI;
}

void	find_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->only_map_h)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr("NSWE", game->map[i][j]))
			{
				game->pos_x = (float) j + 0.5f;
				game->pos_y = (float) i + 0.5f;
				find_angle_view(game, game->map[i][j]);
				return ;
			}
		}
	}
}

void	ft_resoures_initialisation(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->txt[i].img = mlx_xpm_file_to_image(game->mlx,
				game->path_nswe[i], &game->txt[i].width, &game->txt[i].height);
		if (!game->txt[i].img)
		{
			ft_putstr_fd("Error\nCann't read file '", 2);
			ft_putstr_fd(game->path_nswe[i], 2);
			ft_putstr_fd("'\n", 2);
			ft_destroy_exit(game);
		}
		game->txt[i].addr = mlx_get_data_addr(game->txt[i].img,
				&game->txt[i].bits_per_pixel, &game->txt[i].line_length,
				&game->txt[i].endian);
	}
}

void	start_game(t_game *game)
{
	find_position(game);
	game->mlx = mlx_init();
	bonus_map_init_pictures(game);
	ft_resoures_initialisation(game);
	game->win = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3d");
	ft_redraw(game);
	mlx_hook(game->win, ON_KEYDOWN, KeyPressMask, ft_key, game);
	mlx_hook(game->win, ON_DESTROY, NoEventMask, ft_destroy_exit, game);
	mlx_loop(game->mlx);
}
