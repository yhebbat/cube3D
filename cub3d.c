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
	//draw_all_rays();

}
int		draw_player()
{

    float   j;
    float   zb;
    float   x;
    float   y;

	// ft_jareb();
	// draw_map();
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
	//printf("%d %d  \n",g_player.walk_d,g_player.turn_d);
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
	//printf("alo\n");
	
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
	// draw_player();
	// draw_line_of_player();
	draw_all_rays();
	draw_player();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
}
int		ft_depends()
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	//mlx_hook()
	//ft_jareb();
	//draw_map();
	//draw_player();
	move();
	// mlx_hook(g_mlx.win, 3, 0, key_release, &g_mlx);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}
/*
void	ft_rread()
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	fd = open("map.cub", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[i] == "1")
				draw_map();

	}
//		printf("%s\n", line);
}
*/
int		main()
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_HEIGHT, WIN_WIDTH, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.mlx, WIN_HEIGHT, WIN_WIDTH);

	//ft_rread();
	init_player();
	init_move();
	mlx_loop_hook(g_mlx.mlx,ft_depends,(void*)0);
	mlx_loop(g_mlx.mlx);
	return (0);
}