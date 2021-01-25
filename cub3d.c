/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:37:45 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 15:36:04 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int				wall_collision(float x, float y)
{
	int			grid_x;
	int			grid_y;

	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
	if (grid_y < 0 || grid_y >= g_sizeofmap ||
			grid_x < 0 || grid_x >= g_biglen)
		return (0);
	if (g_map[grid_y][grid_x] == '1' || g_map[grid_y][grid_x] == ' ')
		return (1);
	if (g_map[grid_y][grid_x] == '2')
		return (2);
	return (0);
}

void			draw_map(void)
{
	int			x;
	int			y;

	y = 1;
	while (y < g_sizeofmap)
	{
		x = 1;
		while (x < g_biglen)
		{
			if (g_map[y][x] == '1')
				draw_morba3(y * TILE_SIZE, x * TILE_SIZE, 0xffff00);
			if (g_map[y][x] == 'E' || g_map[y][x] == 'S'
					|| g_map[y][x] == 'N' || g_map[y][x] == 'W')
				g_map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void			ft_move(void)
{
	float		move_step;
	float		new_posx;
	float		new_posy;

	ft_jareb();
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	move_step = g_player.move_speed * g_player.walk_d;
	new_posy = g_player.y + sin(g_player.rotation_angle) * move_step;
	new_posx = g_player.x + cos(g_player.rotation_angle) * move_step;
	if (g_player.walk_r != 0)
	{
		move_step = g_player.move_speed * g_player.walk_r;
		new_posy = g_player.y - cos(g_player.rotation_angle) * move_step;
		new_posx = g_player.x + sin(g_player.rotation_angle) * move_step;
	}
	if (!wall_collision(new_posx, g_player.y))
		g_player.x = new_posx;
	if (!wall_collision(g_player.x, new_posy))
		g_player.y = new_posy;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	cast_all_rays();
	ft_sprite();
	draw_map();
	draw_player();
}

void			ft_check_save(char *str)
{
	int sv;

	sv = 0;
	if (ft_strncmp(str, "--save", 7) == 0)
		sv = 1;
	else
		ft_error("Error\n2nd argument incorrect");
}

int				main(int ac, char **av)
{
	if (ac > 3 || ac < 2)
	{
		ft_error("Error\nLe Nombre d'argument en compilation est faut");
		return (0);
	}
	ft_check_extention(av[1]);
	if (av[2])
		ft_check_save(av[2]);
	ft_data_init();
	ft_check_file(av[1]);
	init_mlx();
	init_player();
	init_move();
	ft_get_textures();
	init_sprite();
	mlx_loop_hook(g_mlx.mlx, ft_depends, (void*)0);
	mlx_loop(g_mlx.mlx);
	return (0);
}
