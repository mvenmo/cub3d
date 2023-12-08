/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:58 by botilia           #+#    #+#             */
/*   Updated: 2022/07/15 14:30:14 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define ARROW_UP		126
#  define ARROW_DOWN	125
#  define ARROW_LEFT	123
#  define ARROW_RIGHT	124
#  define KEY_W			13
#  define KEY_A			0
#  define KEY_S			1
#  define KEY_D			2
#  define ESC_KEY		53
#  define KEY_Q			12
# elif __linux
#  include "../mlx_linux/mlx.h"
#  define ARROW_UP		65362
#  define ARROW_DOWN	65364
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
#  define KEY_W			119
#  define KEY_A			97
#  define KEY_S			115
#  define KEY_D			100
#  define ESC_KEY		65307
#  define KEY_Q			113
# else
#  error Stop compilation: unknown system
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	char	**all_map;
	char	**trim_map;
	int		max_h;
	char	*path_nswe[4];
	char	**map;
	int		only_map_h;
	int		map_l;

	int		color_ceiling;
	int		color_floor;

	float	pos_x;
	float	pos_y;
	float	view;
	float	txt_w;
	int		txt_idx;

	void	*mlx;
	void	*win;
	t_img	img;
	t_img	txt[4];

	t_img	npc_img;
	t_img	wall_img;
	int		minimap_on;

}	t_game;

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

# define WINDOW_W		640
# define WINDOW_H		480
# define ANGLE_STEP		0.02f
# define LINEAR_STEP	0.3f
# define FOV			1.047f // Field Of Vision 60 degrees
# define MAP_SCALE		4

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	NoEventMask = 0L,
	KeyPressMask = 1L<<0,
	KeyReleaseMask = 1L<<1,
	ButtonPressMask	= 1L<<2,
	ButtonReleaseMask = 1L<<3,
	EnterWindowMask	= 1L<<4,
	LeaveWindowMask = 1L<<5,
	PointerMotionMask = 1L<<6,
	PointerMotionHintMask = 1L<<7,
	Button1MotionMask = 1L<<8,
	Button2MotionMask = 1L<<9,
	Button3MotionMask = 1L<<10,
	Button4MotionMask = 1L<<11,
	Button5MotionMask = 1L<<12,
	ButtonMotionMask = 1L<<13,
	KeymapStateMask = 1L<<14,
	ExposureMask = 1L<<15,
	VisibilityChangeMask = 1L<<16,
	StructureNotifyMask = 1L<<17,
	ResizeRedirectMask = 1L<<18,
	SubstructureNotifyMask = 1L<<19,
	SubstructureRedirectMask = 1L<<20,
	FocusChangeMask = 1L<<21,
	PropertyChangeMask = 1L<<22,
	ColormapChangeMask = 1L<<23,
	OwnerGrabButtonMask = 1L<<24
};

// utils
char		**ft_free(char **mass);
void		free_all(t_game *game);
void		error_exit(t_game *game, int i);
int			ft_sign(float f);

// map_param
void		map_heigth(t_game *game, char *argv);
void		read_map(t_game *game, char *argv);
void		analizator_map(t_game *game);

// get_paths
char		*init_path_to_resources(t_game *game, char *string);
int			get_path_to_resources(t_game *game, char *string);

// get_color
int			my_atoi(t_game *game, char *str);
void		init_color_floor_and_ceiling(t_game *game, char *string, int i);
int			get_colors(t_game *game, char *string);

// get_and_check_map
void		get_max_lenght(t_game *game);
void		check_border2(t_game *game);
void		inside_check_border2(t_game *game, int i, int j);
void		pruning_map(t_game *game, int ps);
void		check_border(t_game *game);
int			find_begin_map_position(t_game *game, int i);
void		check_desastr(t_game *game, int position);
void		check_symbol_map(t_game *game, int ps);
void		only_map(t_game *game, int position);

// game
void		find_position(t_game *game);
void		ft_resoures_initialisation(t_game *game);
void		start_game(t_game *game);

// draw
void		ft_line(t_game *game, int w, float dist);
void		ft_redraw(t_game *game);

// raycasting
float		ft_ray(t_game *game, float v);
void		ft_ray_casting(t_game *game);

// moving keys destroy
void		ft_move(t_game *game, int direction);
int			ft_key(int keycode, t_game *game);
int			ft_destroy_exit(t_game *game);

////// bonus
void		bonus_map_init_pictures(t_game *game);
void		print_bonus_map_pictures(t_game *game);

#endif
