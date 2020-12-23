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


#include "mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	// y *= MINIMAP;
	// x *= MINIMAP;
	 g_mlx.addr[(y * g_mlx.size_line / 4) + x] = color;
}
void	draw_morba3(int j, int k, int color)
{
	int		x;
	int		y;
	int		c;

	x = j + 64;
	y = k + 64;
    while (j < x)
    {
        c = k;
        while (c < y)
        {
			my_mlx_pixel_put(c, j, color);
			c++;
        }
		j++;   
    }
}
void	draw_map()
{
    int		j;
    int		k;

	j = 0;
    while (j < MAP_ROWS)
    {
		k = 0;
		while (k < MAP_COLS)
        {
            if (map[j][k] == 1)
				draw_morba3(j * TILE_SIZE, k * TILE_SIZE, 0xffff00);
            // else
            //     draw_morba3(j * TILE_SIZE, k * TILE_SIZE, 0xffffff);
            k++;
        }
        j++;
    }
}
void	init_player()
{
	g_player.x = WIN_HEIGHT / 2;
	g_player.y = WIN_WIDTH / 2;
	g_player.rotation_angle = PI / 2;
	g_player.rotation_speed = 3 * (PI / 180);
	g_player.move_speed = 10;
	g_player.walk_d = 0;
	g_player.turn_d = 0;
	g_player.angle = (PI / 180);
}
void	init_move()
{
	g_player.turn_d = 0;
	g_player.walk_d = 0;
}
void	ft_jareb()
{
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	g_mlx.img = mlx_new_image(g_mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	g_mlx.addr = (int *)mlx_get_data_addr(g_mlx.img,
		&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}
float		normalize_angle(float	angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}
/*void	draw_rays()
{
	float	i;
	float	x;
	float	y;
	float	k;

	i = g_player.rotation_angle - (PI / 6);
	while (i < g_player.rotation_angle + (PI / 6))
	{
		k = 1;
		while (k)
		{
			x = g_player.x + cos(g_player.rotation_angle) * k;
			y = g_player.y + sin(g_player.rotation_angle) * k;
			my_mlx_pixel_put(x, y, 0x99ff33);
			k++;
		}
		i += (FOV / NUM_RAYS);
	}
	
}*/
void	rayy(float ray_angle)
{
	int		k;
	float	x;
	float	y;
	int		check_x;
	int		check_y;

	g_player.angle = ray_angle;
	k = 1;
	//g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	while (k)
	{
		x = g_player.x + cos(g_player.angle) * k;
		y = g_player.y + sin(g_player.angle) * k;
		check_x = (int)(x / TILE_SIZE);
		check_y = (int)(y / TILE_SIZE);
		if (map[check_y][check_x] == 1)
			break;
		my_mlx_pixel_put(x, y, 0x99ff33);
		k++;
	}
}
void	draw_all_rays()
{
	float	ray_angle;
	int		i;
	int		columnid;

	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	i = 0;
	columnid = 0;

	while (i < NUM_RAYS)
	{
		rayy(ray_angle);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		columnid++;
		i++;
	}
	
}
float	distancebetweenpts(float xd, float yd, float xf, float yf)
{
	return (sqrt((xf - xd) * (xf - xd) + (yd - yf) * (yd - yf)));
}
void	horiz_inter(float ray_angle, int strip_id)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Yi = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	Xi = g_player.x + (g_player.y - Yi) / tan(ray_angle);
	deltay = TILE_SIZE;
	deltay *= g_tray.ray_facingup ? -1 : 1;
	deltax = TILE_SIZE / tan(ray_angle);
	deltax *= (g_tray.ray_facingleft && deltax > 0) ? -1 : 1;
	deltax *= (g_tray.ray_facingright && deltax < 0) ? -1 : 1;
	g_tray.inter_h_x = Xi;
	g_tray.inter_h_y = Yi + (g_tray.ray_facingup ? -1 : 0);
	while (g_tray.inter_h_x >= 0 && g_tray.inter_h_x <= WIN_WIDTH && g_tray.inter_h_y >= 0 && g_tray.inter_h_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_h_x / TILE_SIZE;
		g_tray.ytocheck = g_tray.inter_h_y / TILE_SIZE;

		if (map[(int)g_tray.xtocheck][(int) g_tray.ytocheck])
		{
			g_tray.h_wallhit_x = g_tray.inter_h_x;
			g_tray.h_wallhit_y = g_tray.inter_h_y;
			g_tray.h_wallcontent = map[(int) floor(g_tray.xtocheck / TILE_SIZE)][(int) floor(g_tray.ytocheck / TILE_SIZE)];
			g_tray.h_wallhit = 1;
			break;
		}else
		{
			g_tray.inter_h_y += deltay;
			g_tray.inter_h_x += deltax;
		}
	}
}
void	verti_inter(float ray_angle, int strip_id)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Xi = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	Yi = g_player.y + (g_player.x - Xi) * tan(ray_angle);
	deltax = TILE_SIZE;
	deltax *= g_tray.ray_facingup ? -1 : 1;
	deltay = TILE_SIZE * tan(ray_angle);
	deltay *= (g_tray.ray_facingup && deltax > 0) ? -1 : 1;
	deltay *= (g_tray.ray_facingdown && deltax < 0) ? -1 : 1;
	g_tray.inter_v_x = Xi + (g_tray.ray_facingleft ? -1 : 0);
	g_tray.inter_v_y = Yi;
	while (g_tray.inter_v_x >= 0 && g_tray.inter_v_x <= WIN_WIDTH && g_tray.inter_v_y >= 0 && g_tray.inter_v_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_v_x / TILE_SIZE;
		g_tray.ytocheck = g_tray.inter_v_y / TILE_SIZE;
		//printf("x ---- %f \n y ---- %f\n",g_tray.xtocheck, g_tray.ytocheck );
		if (map[(int)g_tray.xtocheck][(int)g_tray.ytocheck])
		{
			g_tray.v_wallhit_x = g_tray.inter_v_x;
			g_tray.v_wallhit_y = g_tray.inter_v_y;
			g_tray.v_wallcontent = map[(int)g_tray.xtocheck][(int)g_tray.ytocheck];
			g_tray.v_wallhit = 1;
			break;
		}else
		{
			g_tray.inter_v_y += deltay;
			g_tray.inter_v_x += deltax;
		}
	}	
}
void	cast_ray(float ray_angle, int strip_id)
{
	ray_angle = normalize_angle(ray_angle);
	g_tray.ray_facingdown = (ray_angle > 0 && ray_angle < PI) ? 1 : 0;
	g_tray.ray_facingup = !g_tray.ray_facingdown;
	g_tray.ray_facingright = ((ray_angle < PI / 2 && ray_angle > 0)|| (ray_angle > ((3 * PI) / 2) && ray_angle < 2 * PI)) ? 1 : 0;
	g_tray.ray_facingleft = !g_tray.ray_facingright;
	horiz_inter(ray_angle, strip_id);
	verti_inter(ray_angle, strip_id);
	float	h_hit_distance = g_tray.h_wallhit
		? distancebetweenpts(g_player.x, g_player.y, g_tray.h_wallhit_x, g_tray.h_wallhit_y)
		: INT_MAX;
	float	v_hit_distance = g_tray.v_wallhit
		? distancebetweenpts(g_player.x, g_player.y, g_tray.v_wallhit_x, g_tray.v_wallhit_y)
		: INT_MAX;
	if (v_hit_distance < h_hit_distance)
	{
		g_ray[strip_id].distance = v_hit_distance;
		g_ray[strip_id].wall_hitx = g_tray.v_wallhit_x;
		g_ray[strip_id].wall_hity = g_tray.v_wallhit_y;
		g_ray[strip_id].wall_hit_content = g_tray.v_wallcontent;
		g_ray[strip_id].was_hit_v = 1;
	}else
	{
		g_ray[strip_id].distance = h_hit_distance;
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
		cast_ray(ray_angle, strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		strip_id++;
	}
}
void	draw_line_of_player()
{
	int		k;
	float	x;
	float	y;

	k = PLAYERLINE;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	while (k)
	{
		x = g_player.x + cos(g_player.rotation_angle) * k;
		y = g_player.y + sin(g_player.rotation_angle) * k;
		my_mlx_pixel_put(x, y, 0xff0000);
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
            my_mlx_pixel_put(x, y, 0xff0000);
            zb += 0.1;
        }
        j--;
    }
	draw_line_of_player();
	return (0);
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
int	check_wall(float posx, float posy)
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
void	move()
{
	float	move_step;
	float	new_posx;
	float	new_posy;
	int		r;

	ft_jareb();
	move_step = g_player.walk_d * g_player.move_speed;
	new_posy = g_player.y + sin(g_player.rotation_angle) * move_step;
	new_posx = g_player.x + cos(g_player.rotation_angle) * move_step;
	r = check_wall(new_posx, new_posy);
	if (r < 0)
	{
		g_player.y = new_posy;
		g_player.x = new_posx;
	}
	draw_map();
	draw_player();
	cast_all_rays();
	draw_all_rays();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
}
int		ft_depends()
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	move();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}

int		main()
{
	int	i=0;
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_HEIGHT, WIN_WIDTH, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	init_player();
	init_move();
	mlx_loop_hook(g_mlx.mlx,ft_depends,(void*)0);
	mlx_loop(g_mlx.mlx);
	return (0);
} 