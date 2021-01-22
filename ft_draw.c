/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:12:14 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 15:29:05 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

/*
**void		draw_line_2(float y, float x, float y1,
**float x1, float ray_angle, int color)
**{
**	int		dist;
**	float	i;
**	float	j;
**	float	c;
**
**	j = y;
**	c = x;
**	i = 0;
**	dist = distancebetweenpts(x, y, x1, y1);
**	ray_angle = normalize_angle(ray_angle);
**	while (i < dist)
**	{
**		x = c + (i * cos(ray_angle));
**		y = j + (i * sin(ray_angle));
**		my_mlx_pixel_put(y, x, color);
**		i++;
**	}
**}
*/

void		draw_player(void)
{
	float	j;
	float	zb;
	float	x;
	float	y;

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
	draw_line_of_player();
}

void		draw_line_of_player(void)
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

void		draw_morba3(int j, int k, int color)
{
	int		x;
	int		y;
	int		c;

	y = j + 64;
	x = k + 64;
	while (j < y)
	{
		c = k;
		while (c < x)
		{
			my_mlx_pixel_put(j, c, color);
			c++;
		}
		j++;
	}
}
