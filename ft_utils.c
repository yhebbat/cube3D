/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:44:42 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 17:09:39 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	my_mlx_pixel_put(int y, int x, int color)
{
	y *= MINIMAP;
	x *= MINIMAP;
	if (x >= 0 && x < g_data.win_width && y >= 0
			&& y < g_data.win_height)
		g_mlx.addr[(x + (y * g_data.win_width))] = color;
}

void	my_mlx_pixel_put_3d(int y, int x, int color)
{
	if (x >= 0 && x < g_data.win_width && y >= 0
			&& y < g_data.win_height)
		g_mlx.addr[(x + (y * g_data.win_width))] = color;
}

float	normalize_angle(float angle)
{
	while (angle > 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distancebetweenpts(float xd, float yd, float xf, float yf)
{
	if (xf == -1 || yf == -1)
		return (INT_MAX);
	return (sqrt((xf - xd) * (xf - xd) + (yd - yf) * (yd - yf)));
}

void	ft_jareb(void)
{
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	mlx_clear_window(g_mlx.mlx, g_mlx.win);
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_data.win_width, g_data.win_height);
	g_mlx.addr = (int *)mlx_get_data_addr(g_mlx.img,
			&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}
