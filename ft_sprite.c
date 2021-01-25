/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:00:58 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 16:18:48 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void			sprite_sort(void)
{
	int			i;
	int			j;
	t_sprite	*tmp;

	i = 0;
	while (i < g_sprite_c)
	{
		j = 0;
		while (j < g_sprite_c - i - 1)
		{
			if (g_sprite[j]->distance <= g_sprite[j + 1]->distance)
			{
				tmp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			update_sprite(void)
{
	int			i;
	int			j;
	int			spt_id;

	i = -1;
	spt_id = 0;
	while (++i < g_sizeofmap)
	{
		j = -1;
		while (++j < g_biglen)
		{
			if (g_map[i][j] == '2')
			{
				g_sprite[spt_id]->y = (i * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[spt_id]->x = (j * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[spt_id]->distance = distancebetweenpts(
						g_sprite[spt_id]->x, g_sprite[spt_id]->y,
						g_player.x, g_player.y);
				spt_id++;
			}
		}
	}
	sprite_sort();
}

void			render_sprite(int k, int x_fs, int y_fs, int sp_size)
{
	int			i;
	int			j;
	int			color;

	i = -1;
	while (++i < sp_size)
	{
		if (x_fs + i < 0 || y_fs + i > g_data.win_width)
			continue ;
		if (x_fs + i < g_data.win_width)
			if (g_ray[x_fs + i].distance < g_sprite[k]->distance)
				continue ;
		j = -1;
		while (++j < sp_size)
		{
			if (y_fs + j < 0 || y_fs + j > g_data.win_height)
				continue ;
			color = g_sprite[k]->data[g_textures[S].text_width * (j *
					g_textures[S].text_height / sp_size) +
				(i * g_textures[S].text_width / sp_size)];
			if (color)
				my_mlx_pixel_put_3d(y_fs + j, x_fs + i, color);
		}
	}
}

void			sprite_data(int spt_id)
{
	float		x_offset;
	float		y_offset;
	float		sp_angle;
	float		sp_size;

	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	sp_angle = atan2((g_sprite[spt_id]->y) - g_player.y,
			(g_sprite[spt_id]->x) - g_player.x);
	while (sp_angle - g_player.rotation_angle > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - g_player.rotation_angle < -M_PI)
		sp_angle += 2 * M_PI;
	sp_size = (g_data.win_width / g_sprite[spt_id]->distance) * TILE_SIZE;
	x_offset = (sp_angle - g_player.rotation_angle) /
		FOV_ANGLE * g_data.win_width + (g_data.win_width / 2 - sp_size / 2);
	y_offset = (g_data.win_height / 2 - sp_size / 2);
	render_sprite(spt_id, x_offset, y_offset, sp_size);
}

void			ft_sprite(void)
{
	int			spt_id;

	spt_id = -1;
	update_sprite();
	while (++spt_id < g_sprite_c)
		sprite_data(spt_id);
}
