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

#include "cub3d.h"
#include "get_next_line.h"

int		hell[MAP_ROWS][MAP_COLS] = {
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
void	ft_jareb()
{
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_data.win_width, g_data.win_height);
	g_mlx.addr = (int *)mlx_get_data_addr(g_mlx.img,
		&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}

int		check_wall(float posy, float posx)
{
	int x;
	int	y;

	x = (int)posx / TILE_SIZE;
	y = (int)posy /TILE_SIZE;
	if (hell[y][x] == 0)
	{
		return (-1);
	}
	return (1);
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
	if (hell[grid_y][grid_x] == 1)
		return (1);
	return (0);
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
            if (hell[y][x] == 1)
				draw_morba3(y * TILE_SIZE, x * TILE_SIZE, 0xffff00);
            // else
            //     draw_morba3(j * TILE_SIZE, k * TILE_SIZE, 0xffffff);
            x++;
        }
        y++;
    }
}

void	ft_move()
{
	float	move_step;
	float	new_posx;
	float	new_posy;

	ft_jareb();
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	move_step = g_player.move_speed * g_player.walk_d;
	new_posy = g_player.y + sin(g_player.rotation_angle) * move_step;
	new_posx = g_player.x + cos(g_player.rotation_angle) * move_step;
	if (check_wall(new_posy, g_player.x) < 0)
	{
		g_player.y = new_posy;
	}
	if (check_wall(g_player.y, new_posx) < 0)
	{
		g_player.x = new_posx;
	}
	
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	cast_all_rays();
	draw_map();
	draw_player();
}

int		main(int ac, char **av)
{
	if (ac > 3 || ac < 2)
	{
		ft_error("Error\nLe Nombre d'argument en compilation est faut");
		return(0);
	}
	ft_check_extention(av[1]);
	ft_data_init();
	ft_check_file(av[1]);
	init_mlx();
	init_player();
	init_move();
	mlx_loop_hook(g_mlx.mlx, ft_depends, (void*)0);
	
	printf("%d ------------------ %d\n", g_data.win_height, g_data.win_width);
	printf("\n\n\n");
	int i = -1;
	while (++i < 3)
	{
		printf("%d ------------------ %d\n", g_color[i].color_f, g_color[i].color_c);
	}
    i = 0;
    while (i < 5)
	{
		printf("%s ------------------ \n", g_textures[i].texture);
		i++;
	}
	mlx_loop(g_mlx.mlx);
	return (0);
}