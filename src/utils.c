/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:29:15 by botilia           #+#    #+#             */
/*   Updated: 2022/07/14 16:01:35 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_free(char **mass)
{
	int	sizemass;

	sizemass = 0;
	while (mass[sizemass])
	{
		free(mass[sizemass]);
		sizemass++;
	}
	free(mass);
	return (NULL);
}

void	free_all(t_game *game)
{
	int	count;

	if (game->all_map)
		game->all_map = ft_free(game->all_map);
	if (game->trim_map)
		game->trim_map = ft_free(game->trim_map);
	if (game->map)
		free(game->map);
	count = -1;
	while (++count < 4)
	{
		if (game->path_nswe[count])
			free(game->path_nswe[count]);
	}
	free(game);
}

static void	error_exit2(int i)
{
	if (i == 11)
		ft_putstr_fd("Error\nProgram cannot read file\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nAfter NO, SO, WE, EA, C, F must be map\n", 2);
}

void	error_exit(t_game *game, int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nEnter binary file and map\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nYour map must be \".cub\"\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nWrong path to resources \"NO,SO,WE,EA\"\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMemory not allocated\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nValues of color [0,255] or not correct dates\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nCheck parametres -> NO, SO, WE, EA, C, F\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nMap not valid\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nHero in map must be only one \'S W E N\'\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nNot valid ending map\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error\nCheck borders in map\n", 2);
	else
		error_exit2(i);
	free_all(game);
	exit(i);
}

int	ft_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}
