/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:37:45 by yhebbat           #+#    #+#             */
/*   Updated: 2020/11/27 05:37:46 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//line : 265


#include "mlx.h"
#include "cub3d.h"

void	ft_jareb()
{
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	g_mlx.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	g_mlx.addr = (int *)mlx_get_data_addr(g_mlx.img,
		&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}

void	my_mlx_pixel_put(int y, int x, int color)
{
	y *= MINIMAP;
	x *= MINIMAP;
	if (x >= 0 && x < (WIN_WIDTH * MINIMAP)&& y >= 0
		&& y < (WIN_HEIGHT * MINIMAP))
		g_mlx.addr[(x + (y * WIN_WIDTH))] = color;
}
void	my_mlx_pixel_put_3d(int y, int x, int color)
{
	if (x >= 0 && x < WIN_WIDTH&& y >= 0
		&& y < WIN_HEIGHT)
		g_mlx.addr[(x + (y * WIN_WIDTH))] = color;
}
void	init_player()
{
	g_player.x = 24 * TILE_SIZE;
	g_player.y = 13 * TILE_SIZE;
	g_player.rotation_angle = PI / 2;
	g_player.rotation_speed = 3 * (PI / 180);
	g_player.move_speed = 10;
	g_player.angle = (PI / 180);
}

void	init_move()
{
	g_player.walk_d = 0;
	g_player.turn_d = 0;
}

int		key_press(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == UP_ARROW)
		g_player.walk_d = 1;
	if (key == DOWN_ARROW)
		g_player.walk_d = -1;
	if (key == LEFT_ARROW)
		g_player.turn_d = -1;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 1;
	return (0);
}

int		key_release(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == UP_ARROW)
		g_player.walk_d = 0;
	if (key == DOWN_ARROW)
		g_player.walk_d = 0;
	if (key == LEFT_ARROW)
		g_player.turn_d = 0;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 0;
	return (0);
}
int		check_wall(float posy, float posx)
{
	int x;
	int	y;

	x = (int)posx / TILE_SIZE;
	y = (int)posy /TILE_SIZE;
	if (map[y][x] == 0)
	{
		return (-1);
	}
	return (1);
}
void	draw_morba3(int j, int k, int color)
{
	int		x;
	int		y;
	int		c;

	y = j + 64;
	x = k + 64;
	while (j < y)
	{
		c = k;
		while(c < x)
		{
			my_mlx_pixel_put(j, c, color);
			c++;
		}
		j++;
	}
}
void	draw_map()
{
    int		x;
    int		y;

	y = 0;
    while (y < MAP_ROWS)
    {
		x = 0;
		while (x < MAP_COLS)
        {
            if (map[y][x] == 1)
				draw_morba3(y * TILE_SIZE, x * TILE_SIZE, 0xffff00);
			// else
			// 	draw_morba3(y * TILE_SIZE, x * TILE_SIZE, 0x000000);
            x++;
        }
        y++;
    }
}
void	draw_line_of_player()
{
	int		k;
	float	y;
	float	x;

	k = PLAYERLINE;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	while (k)
	{
		y = g_player.y + sin(g_player.rotation_angle) * k;
		x = g_player.x + cos(g_player.rotation_angle) * k;
		my_mlx_pixel_put(y, x, 0xff0000);
		k--;
	}
}

int		draw_player()
{

    float   j;
    float   zb;
    float   x;
    float   y;

    j = RAYON;
    while (j > 0)
    {
        zb = 0;
        while (zb <= 360)
        {
            x = g_player.x + j * cos(zb * g_player.angle);
            y = g_player.y + j * sin(zb * g_player.angle);
            my_mlx_pixel_put(y, x, 0xff0000);
            zb += 0.1;
        }
        j--;
    }
	return (0);
}


void	draw_line_2(float y, float x, float y1, float x1,float ray_angle, int color)
{
	int dist = distancebetweenpts(x, y, x1, y1);
	float i;
	float j = y;
	float c = x;

	i = 0;
	ray_angle = normalize_angle(ray_angle);
	while (i < dist)
	{
		x = c + (i * cos(ray_angle));
		y = j + (i * sin(ray_angle));
		my_mlx_pixel_put(y, x, color);
		i++;
	}
}
// void	draw_line(int Y0, int X0, int Y1, int X1, int color)
// {
// 	int		dx = X1 - X0;
// 	int		dy = Y1 - Y0;
// 	int		i = 0;
// 	int		steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
// 	float	Xinc = dx / (float)steps;
// 	float	Yinc = dy / (float)steps;
// 	float	X = X0;
// 	float	Y = Y0;
// 	while (i < steps)
// 	{
// 		my_mlx_pixel_put(Y, X, color);
// 		X += Xinc;
// 		Y += Yinc;
// 		i++;
// 	}
// }
float		normalize_angle(float	angle)
{
	angle = fmod(angle, TWO_PI);
	while (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}
int		wall_collision(float x, float y)
{
	int		grid_x;
	int		grid_y;

	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
	if (grid_y < 0 || grid_y >= MAP_ROWS ||
	grid_x < 0 || grid_x >= MAP_COLS)
		return (0);
	if (map[grid_y][grid_x] == 1)
		return (1);
	return (0);
}
float	distancebetweenpts(float xd, float yd, float xf, float yf)
{
	if (xf == -1 || yf == -1)
		return (INT_MAX);
	return (sqrt((xf - xd) * (xf - xd) + (yd - yf) * (yd - yf)));
}
void	init_rays()
{	    
	g_tray.ray_facingup = 0;			
	g_tray.ray_facingdown  = 0;		
	g_tray.ray_facingright = 0;
	g_tray.ray_facingleft = 0;		
	g_tray.h_wallhit = 0;
	g_tray.h_wallhit_x = 0;
	g_tray.h_wallhit_y = 0;
	g_tray.h_wallcontent = 0;
	g_tray.inter_v_x = 0;
	g_tray.inter_v_y = 0;
	g_tray.inter_h_x = 0;
	g_tray.inter_h_y = 0;
	g_tray.v_wallhit = 0;
	g_tray.v_wallhit_x = 0;
	g_tray.v_wallhit_y = 0;
	g_tray.v_wallcontent = 0;
	g_tray.xtocheck = 0;
	g_tray.ytocheck = 0;
	g_tray.v_hit_distance = INT_MAX;
	g_tray.h_hit_distance = INT_MAX;
}
void	horiz_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Yi = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingdown)
		Yi += TILE_SIZE;
	Xi = g_player.x + ((Yi - g_player.y) / tan(ray_angle));
	deltay = TILE_SIZE;
	if (g_tray.ray_facingup)
		deltay *= -1;
	deltax = TILE_SIZE / tan(ray_angle);
	if (g_tray.ray_facingright && deltax < 0)
		deltax *= -1;
	if (g_tray.ray_facingleft && deltax > 0)
		deltax *= -1;
	g_tray.inter_h_x = Xi;
	g_tray.inter_h_y = Yi;
	if (g_tray.ray_facingup)
		g_tray.inter_h_y--;
	while (g_tray.inter_h_x >= 0 && g_tray.inter_h_x <= WIN_WIDTH && g_tray.inter_h_y >= 0 && g_tray.inter_h_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_h_x;
		g_tray.ytocheck = g_tray.inter_h_y;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck))
		{
			g_tray.h_wallhit_x = g_tray.inter_h_x;
			g_tray.h_wallhit_y = g_tray.inter_h_y;
			g_tray.h_wallhit = 1;
			break ;
		}
		else
		{
			g_tray.inter_h_x += deltax;
			g_tray.inter_h_y += deltay;
		}
	}		
}

void	verti_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Xi = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingright)
		Xi += TILE_SIZE;
	Yi = g_player.y + ((Xi - g_player.x) * tan(ray_angle));
	deltax = TILE_SIZE;
	if (g_tray.ray_facingleft)
		deltax *= -1;
	deltay = TILE_SIZE * tan(ray_angle);
	if (g_tray.ray_facingdown && deltay < 0)
		deltay *= -1;
	if (g_tray.ray_facingup && deltay > 0)
		deltay *= -1;
	g_tray.inter_v_x = Xi;
	g_tray.inter_v_y = Yi;
	if (g_tray.ray_facingleft)
		g_tray.inter_v_x--;
	while (g_tray.inter_v_x >= 0 && g_tray.inter_v_x <= WIN_WIDTH && g_tray.inter_v_y >= 0 && g_tray.inter_v_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_v_x;
		g_tray.ytocheck = g_tray.inter_v_y;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck))
		{
			g_tray.v_wallhit_x = g_tray.inter_v_x;
			g_tray.v_wallhit_y = g_tray.inter_v_y;
			g_tray.v_wallhit = 1;
			break ;
		}
		else
		{
			g_tray.inter_v_x += deltax;
			g_tray.inter_v_y += deltay;
		}
	}
}
void	check_angle(float angle)
{
	if (angle > 0 && angle < M_PI)
		g_tray.ray_facingdown = 1;
	else
		g_tray.ray_facingup = 1;
	if (angle < M_PI / 2 || angle  > ((3 * M_PI) / 2))
		g_tray.ray_facingright = 1;
  	else
      g_tray.ray_facingleft = 1;
}
void	cast_ray(float ray_angle, int strip_id)
{
	ray_angle = normalize_angle(ray_angle);
	check_angle(ray_angle);
	horiz_inter(ray_angle);
	verti_inter(ray_angle);
	if (g_tray.h_wallhit)
		g_tray.h_hit_distance = distancebetweenpts(g_player.x, g_player.y, g_tray.h_wallhit_x, g_tray.h_wallhit_y);
	if (g_tray.v_wallhit)
		g_tray.v_hit_distance = distancebetweenpts(g_player.x, g_player.y, g_tray.v_wallhit_x, g_tray.v_wallhit_y);
	if (g_tray.v_hit_distance < g_tray.h_hit_distance)
	{
		g_ray[strip_id].distance = g_tray.v_hit_distance;
		g_ray[strip_id].wall_hitx = g_tray.v_wallhit_x;
		g_ray[strip_id].wall_hity = g_tray.v_wallhit_y;
		g_ray[strip_id].wall_hit_content = g_tray.v_wallcontent;
		g_ray[strip_id].was_hit_v = 1;
	}
	else
	{
		g_ray[strip_id].distance = g_tray.h_hit_distance;
		g_ray[strip_id].wall_hitx = g_tray.h_wallhit_x;
		g_ray[strip_id].wall_hity = g_tray.h_wallhit_y;
		g_ray[strip_id].wall_hit_content = g_tray.h_wallcontent;
		g_ray[strip_id].was_hit_v = 0;
	}
    g_ray[strip_id].ray_angle = ray_angle;
    g_ray[strip_id].ray_facingdown = g_tray.ray_facingdown;
    g_ray[strip_id].ray_facingup = g_tray.ray_facingup;
    g_ray[strip_id].ray_facingleft = g_tray.ray_facingleft;
    g_ray[strip_id].ray_facingright = g_tray.ray_facingright;
}
void	cast_all_rays()
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = g_player.rotation_angle  - (FOV_ANGLE / 2);
	while (strip_id < NUM_RAYS)
	{
		init_rays();
		cast_ray(ray_angle, strip_id);
		drawing_3d(strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		draw_line_2(g_player.y, g_player.x, g_ray[strip_id].wall_hity, g_ray[strip_id].wall_hitx, ray_angle, 0xfffff);
		strip_id++;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////DESSINER LES MURS///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void	draw_ceiling(int start, int i)
{
	int f;

	f = 0;
	if (start < 0)
		start = 0;
	while (f <= start)
	{
		my_mlx_pixel_put_3d(f, i, 0x0099ff);
		f++;
	}
}
void	draw_walls(int start, int end, int i)
{
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;
	while (start <= end)
	{
		my_mlx_pixel_put_3d(start, i, 0x996633);
		start++;
	}
	
}
void	draw_floor(int end, int i)
{
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;
	while (end < WIN_HEIGHT)
	{
		my_mlx_pixel_put_3d(end, i, 0x333300);
		end++;
	}
	
}
void	drawing_3d(int i)
{
	float	rw_distance;
	int		rw_height;
	float	dpp;
	float	pw_height;
	int		start;
	int		end;

	rw_height = TILE_SIZE;
	dpp = WIN_WIDTH / (2 * tan(FOV_ANGLE / 2));
	rw_distance = g_ray[i].distance * cos(g_ray[i].ray_angle - g_player.rotation_angle);
	pw_height = (rw_height * dpp) / rw_distance;
	start = (WIN_HEIGHT / 2 ) - (pw_height / 2);
	end = (WIN_HEIGHT / 2 ) + (pw_height / 2);
	draw_ceiling(start, i);
	draw_walls(start, end, i);
	draw_floor(end, i);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void	ft_move()
{
	float	move_step;
	float	new_posx;
	float	new_posy;

	ft_jareb();
	move_step = g_player.move_speed * g_player.walk_d;
	new_posy = g_player.y + sin(g_player.rotation_angle) * move_step;
	new_posx = g_player.x + cos(g_player.rotation_angle) * move_step;
	if (check_wall(new_posy, new_posx) < 0)
	{
		g_player.y = new_posy;
		g_player.x = new_posx;
	}
	cast_all_rays();
	draw_map();
	draw_player();
	draw_line_of_player();
}

int		ft_depends()
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	ft_move();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}

int		main()
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	init_player();
	init_move();
	mlx_loop_hook(g_mlx.mlx, ft_depends, (void*)0);
	mlx_loop(g_mlx.mlx);
	return (0);
}