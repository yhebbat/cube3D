/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:12:35 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/20 16:41:58 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rotationangle(char player_position)
{
	if (player_position == 'N')
		g_player.rotation_angle = (270 * (PI / 180));
	else if (player_position == 'S')
		g_player.rotation_angle = (90 * (PI / 180));
	else if (player_position == 'W')
		g_player.rotation_angle = (180 * (PI / 180));
	else if (player_position == 'E')
		g_player.rotation_angle = (360 * (PI / 180));
}

void	init_player(void)
{
	int		i;
	int		j;

	i = -1;
	g_player.rotation_angle = 0;
	g_sprite_c = 0;
	while (++i < g_sizeofmap)
	{
		j = -1;
		while (++j < g_biglen)
		{
			if (g_map[i][j] == 'E' || g_map[i][j] == 'N'
					|| g_map[i][j] == 'S' || g_map[i][j] == 'W')
			{
				set_rotationangle(g_map[i][j]);
				g_player.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				g_player.y = (i * TILE_SIZE) + TILE_SIZE / 2;
			}
			else if (g_map[i][j] == '2')
				g_sprite_c++;
		}
	}
	g_player.rotation_speed = 3 * (PI / 180);
	g_player.move_speed = 5;
	g_player.angle = PI / 2;
}

void	init_move(void)
{
	g_player.walk_d = 0;
	g_player.turn_d = 0;
	g_player.walk_r = 0;
}

void	init_rays(void)
{
	g_tray.ray_facingup = 0;
	g_tray.ray_facingdown = 0;
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

void	init_sprite(void)
{
	int		i;

	i = 0;
	if (!(g_sprite = malloc(sizeof(t_sprite *) * (g_sprite_c + 1))))
		return ;
	while (i < g_sprite_c)
	{
		if (!(g_sprite[i] = malloc(sizeof(t_sprite))))
			return ;
		g_sprite[i]->ptr = mlx_xpm_file_to_image(g_mlx.mlx,
			g_textures[S].texture, &g_textures[S].text_width,
			&g_textures[S].text_height);
		g_sprite[i]->data = (int *)mlx_get_data_addr(g_sprite[i]->ptr,
				&g_sprite[i]->bpp,
				&g_sprite[i]->size_line,
				&g_sprite[i]->endian);
		i++;
	}
	g_sprite[i] = NULL;
}

void	init_mlx(void)
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, g_data.win_width,
			g_data.win_height, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_data.win_width, g_data.win_height);
}
