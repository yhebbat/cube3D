/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:37:52 by yhebbat           #+#    #+#             */
/*   Updated: 2020/11/27 05:37:53 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "lbft/libft.h"
# include "gnl/get_next_line.h"

typedef char t_bool;

# define MAP_ROWS 16
# define MAP_COLS 30

int		map[MAP_ROWS][MAP_COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53

# define TILE_SIZE 64

# define WIN_WIDTH (MAP_COLS* TILE_SIZE)
# define WIN_HEIGHT (MAP_ROWS * TILE_SIZE)

# define PI 3.14159265
# define TWO_PI 6.28318530
# define RAYON 5
# define PLAYERLINE 50

# define FOV_ANGLE (60 * (PI / 180))
# define NUM_RAYS WIN_WIDTH

# define MINIMAP 0.2
// THIS STRUCTURE IS MY MAIN MLX STRUCTURE
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct	s_player
{
	float		x;
    float		y;
    float		rotation_angle; //PI/2
    float		rotation_speed; //3 * (pi / 180)
	int			walk_d;
	int			turn_d;
	float		move_speed; //3
    float       angle;
}				t_player;
typedef struct  s_ray
{
    float       ray_angle;
    float       wall_hitx;
    float       wall_hity;
    float		distance;
    int         was_hit_v;
    int			ray_facingup;
	int			ray_facingdown;
	int			ray_facingright;
	int			ray_facingleft;
	int			wall_hit_content;        
}               t_ray;
typedef struct	s_tray
{
    int			ray_facingup;
	int			ray_facingdown;
	int			ray_facingright;
	int			ray_facingleft;
	int			h_wallhit;
	float		h_wallhit_x;
	float		h_wallhit_y;
	int			h_wallcontent;
	float		h_hit_distance;
	float		v_hit_distance;
	float		inter_v_x;
	float		inter_v_y;
	float		inter_h_x;
	float		inter_h_y;
	int			v_wallhit;
	float		v_wallhit_x;
	float		v_wallhit_y;
	int			v_wallcontent;
	float		xtocheck;
	float		ytocheck;
}               t_tray;
typedef	struct s_data
{
	int			win_width;
	int			win_height;
}				t_data;

t_data			g_data;
t_tray          g_tray;
t_ray			g_ray[NUM_RAYS];
t_mlx			g_mlx;
t_player		g_player;

void	drawing_3d(int i);
float		normalize_angle(float	angle);
float	distancebetweenpts(float xd, float yd, float xf, float yf);
#endif