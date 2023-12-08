/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:11:20 by botilia           #+#    #+#             */
/*   Updated: 2022/07/14 15:30:38 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_begin_map_position(t_game *game, int i)
{
	while (game->all_map[++i])
	{
		if (game->trim_map[i][0] != '\0' && game->trim_map[i][0] != '1')
			error_exit(game, 12);
		if (game->trim_map[i][0] == '1')
			break ;
	}
	return (i);
}

void	check_desastr(t_game *game, int position)
{
	int	j;

	while (++position < game->only_map_h)
	{
		j = 0;
		while (game->map[position][j])
		{
			if (ft_strchr(" 01NSWE", game->map[position][j]))
				error_exit(game, 9);
			else
				j++;
		}
	}
}

void	check_symbol_map(t_game *game, int ps)
{
	int		i;
	int		j;
	int		hero;

	i = -1;
	hero = 0;
	while (++i < game->only_map_h)
	{
		j = 0;
		if (game->trim_map[ps][j] != '1')
			check_desastr(game, i);
		while (game->trim_map[ps][j] != '\0')
		{
			if (!ft_strchr(" 01NSWE", game->trim_map[ps][j]))
				error_exit(game, 7);
			if (ft_strchr("NSWE", game->trim_map[ps][j]))
				hero++;
			j++;
		}
		ps++;
	}
	if (hero > 1 || hero == 0)
		error_exit(game, 8);
}

void	check_border(t_game *game)
{
	int	i;
	int	j;
	int	len_string;

	i = -1;
	while (++i < game->only_map_h)
	{
		j = 0;
		len_string = ft_strlen(game->map[i]);
		while (j < len_string)
		{
			if (ft_strchr("0NSEW", game->map[i][j]))
			{
				if ((i == 0) || (i == game->only_map_h - 1)
					|| (j == 0) || (game->map[i][len_string - 1] == 0))
					error_exit(game, 10);
				if ((game->map[i][j - 1] == ' ') || (game->map[i][j + 1] == ' ')
		|| (game->map[i - 1][j] == ' ') || (game->map[i + 1][j] == ' ')
		|| (game->map[i - 1][j + 1] == ' ') || (game->map[i - 1][j - 1] == ' ')
		|| (game->map[i + 1][j + 1] == ' ') || (game->map[i + 1][j - 1] == ' '))
					error_exit(game, 10);
			}
			j++;
		}
	}
}

void	only_map(t_game *game, int position)
{
	int	ps;

	ps = position;
	game->map = malloc(sizeof(char *) * (game->max_h + 1));
	if (!game->map)
		error_exit(game, 4);
	while (position < game->max_h)
	{
		game->map[game->only_map_h] = game->all_map[position];
		game->only_map_h++;
		position++;
	}
	game->map[position] = NULL;
	check_symbol_map(game, ps);
	pruning_map(game, ps);
	check_border(game);
	check_border2(game);
	get_max_lenght(game);
	game->trim_map = ft_free(game->trim_map);
}
