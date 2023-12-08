/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:53:03 by botilia           #+#    #+#             */
/*   Updated: 2022/07/12 14:48:22 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_heigth(t_game *game, char *argv)
{
	int		heigth;
	int		fd;
	char	*line;

	heigth = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(game, 11);
	line = get_next_line(fd);
	while (line)
	{
		heigth++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	game->max_h = heigth;
}

void	analizator_map(t_game *game)
{
	int		i;
	int		count_param;

	count_param = 0;
	i = -1;
	while (++i < game->max_h)
	{
		if ((!ft_strchr("NSWECF", game->trim_map[i][0]) && count_param < 6))
			error_exit(game, 6);
		if ((game->trim_map[i][0] == 'N' || game->trim_map[i][0] == 'S'
		|| game->trim_map[i][0] == 'W' || game->trim_map[i][0] == 'E')
			&& get_path_to_resources(game, game->trim_map[i]))
			count_param++;
		else if ((game->trim_map[i][0] == 'C' || game->trim_map[i][0] == 'F')
			&& get_colors(game, game->trim_map[i]))
			count_param++;
		if (count_param == 6)
			break ;
	}
	i = find_begin_map_position(game, i);
	only_map(game, i);
}

void	read_map(t_game *game, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	game->all_map = malloc(sizeof(char *) * (game->max_h + 1));
	if (!game->all_map)
		error_exit(game, 4);
	game->trim_map = malloc(sizeof(char *) * (game->max_h + 1));
	if (!game->trim_map)
		error_exit(game, 4);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(game, 11);
	i = -1;
	while (++i < game->max_h)
	{
		line = get_next_line(fd);
		game->all_map[i] = ft_strdup(line);
		game->trim_map[i] = ft_strtrim(line, " ");
		free(line);
	}
	game->all_map[i] = NULL;
	game->trim_map[i] = NULL;
	close(fd);
	analizator_map(game);
}
