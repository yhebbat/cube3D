/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:37:52 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/11 15:58:44 by yhebbat          ###   ########.fr       */
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
# include "get_next_line.h"

# define MAP_ROWS 16
# define MAP_COLS 30

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

# define WIN_WIDTH (MAP_COLS * TILE_SIZE)

# define PI 3.14159265
# define TWO_PI 6.28318530
# define RAYON 5
# define PLAYERLINE 50
# define FOV_ANGLE 1.04719755

/*
**(60 * (PI / 180))
*/
# define NUM_RAYS WIN_WIDTH

# define MINIMAP 0.2

/*
**THIS STRUCTURE IS MY MAIN MLX STRUCTURE
*/
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
	float		rotation_angle;
	float		rotation_speed;
	int			walk_d;
	int			turn_d;
	int			walk_r;
	float		move_speed;
	float		angle;
}				t_player;

typedef struct	s_ray
{
	float		ray_angle;
	float		wall_hitx;
	float		wall_hity;
	float		distance;
	int			was_hit_v;
	int			ray_facingup;
	int			ray_facingdown;
	int			ray_facingright;
	int			ray_facingleft;
	int			wall_hit_content;
}				t_ray;

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
}				t_tray;

t_tray			g_tray;
t_ray			g_ray[NUM_RAYS];
t_mlx			g_mlx;
t_player		g_player;

void			ft_render(int i);
float			normalize_angle(float	angle);
void			init_player(void);
void			init_rays(void);
void			init_move(void);
void			init_mlx(void);
void			my_mlx_pixel_put(int y, int x, int color);
void			my_mlx_pixel_put_3d(int y, int x, int color);
float			distancebetweenpts(float xd, float yd, float xf, float yf);
void			ft_render(int i);
void			render_floor(int bot, int i);
void			render_wall(int bot, int start, int i, float wall_h, int t);
void			render_ceiling(int start, int i);
int				ft_depends(void);
int				key_release(int key);
int				key_press(int key);
void			ft_move(void);
void			draw_morba3(int j, int k, int color);
void			draw_line_of_player(void);
void			draw_player(void);
void			draw_line_2(float y, float x, float y1, float x1,
							float ray_angle, int color);
void			draw_line(int y0, int x0, int y1, int x1, int color);
void			check_angle(float angle);
int				wall_collision(float x, float y);
//int				check_wall(float posy, float posx);
void			verti_inter(float ray_angle);
void			horiz_inter(float ray_angle);
void			cast_all_rays(void);
void			cast_ray(float ray_angle, int strip_id);
void			remplir_gray(float ray_angle, int strip_id);
#endif