/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:57:00 by mvenmo            #+#    #+#             */
/*   Updated: 2022/08/09 12:49:16 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_ray_initial_calculations(t_game *game, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = ft_sign(r->dx);
	r->sy = ft_sign(r->dy);
	r->vert_x = (int) game->pos_x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) game->pos_y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

static void	ft_ray_next_step_calculation(t_game *game, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = game->pos_y + r->dy / r->dx * (r->vert_x - game->pos_x);
		r->vert_dist = sqrt(pow(game->pos_x - r->vert_x, 2.0)
				+ pow(game->pos_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = game->pos_x + r->dx / r->dy * (r->hor_y - game->pos_y);
		r->hor_dist = sqrt(pow(game->pos_x - r->hor_x, 2.0)
				+ pow(game->pos_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

static float	ft_save_color(t_game *game, float dist, int color_idx, float w)
{
	game->txt_idx = color_idx;
	game->txt_w = w;
	return (dist);
}

float	ft_ray(t_game *game, float v)
{
	t_ray	r;

	ft_ray_initial_calculations(game, &r, v);
	while (1)
	{
		ft_ray_next_step_calculation(game, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (game->map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1) / 2] == '1')
				return (ft_save_color(game, r.vert_dist, r.sx + 1, r.vert_w));
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
			else
				r.hor_y += r.sy;
		}
	}
}

void	ft_ray_casting(t_game *game)
{
	int		x;
	float	dv;
	float	v;

	v = game->view - FOV / 2;
	dv = FOV / (WINDOW_W - 1);
	x = -1;
	while (++x < WINDOW_W)
	{
		ft_line(game, x, ft_ray(game, v) * cos(game->view - v));
		// ft_line(game, x, ft_ray(game, v));
		v += dv;
	}
}
