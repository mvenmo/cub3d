/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:21:26 by botilia           #+#    #+#             */
/*   Updated: 2022/07/15 12:58:58 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv, t_game *game)
{
	char	*tmp;

	if (!game)
		error_exit(game, 4);
	if (argc != 2)
		error_exit(game, 1);
	tmp = ft_strrchr(argv[1], '.');
	if (ft_strncmp(tmp, ".cub\0", 5))
		error_exit(game, 2);
}

void	init_struct(t_game *game)
{
	int	i;

	game->color_ceiling = -1;
	game->color_floor = -1;
	game->only_map_h = 0;
	game->map_l = 0;
	i = -1;
	while (++i < 4)
	{
		game->path_nswe[i] = NULL;
		game->txt[i].img = NULL;
	}
	game->minimap_on = 0;
	game->all_map = NULL;
	game->trim_map = NULL;
	game->map = NULL;
	game->win = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	init_struct(game);
	check_args(argc, argv, game);
	map_heigth(game, argv[1]);
	read_map(game, argv[1]);
	start_game(game);
	return (0);
}
