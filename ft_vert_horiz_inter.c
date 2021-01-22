/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vert_horiz_inter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:13:52 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/20 16:27:27 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	horiz_iwall_collision(float deltay, float deltax)
{
	while (g_tray.inter_h_x > 0 && g_tray.inter_h_x < g_biglen * TILE_SIZE
		&& g_tray.inter_h_y > 0 && g_tray.inter_h_y < g_sizeofmap * TILE_SIZE)
	{
		g_tray.xtocheck = g_tray.inter_h_x;
		g_tray.ytocheck = g_tray.inter_h_y;
		if (g_tray.ray_facingup)
			g_tray.ytocheck--;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck) == 1)
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

void	horiz_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	xi;
	float	yi;

	yi = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingdown)
		yi += TILE_SIZE;
	xi = g_player.x + ((yi - g_player.y) / tan(ray_angle));
	deltay = TILE_SIZE;
	if (g_tray.ray_facingup)
		deltay *= -1;
	deltax = TILE_SIZE / tan(ray_angle);
	if (g_tray.ray_facingright && deltax < 0)
		deltax *= -1;
	if (g_tray.ray_facingleft && deltax > 0)
		deltax *= -1;
	g_tray.inter_h_x = xi;
	g_tray.inter_h_y = yi;
	horiz_iwall_collision(deltay, deltax);
}

void	verti_iwall_collision(float deltay, float deltax)
{
	while (g_tray.inter_v_x >= 0 && g_tray.inter_v_x <= (g_biglen * TILE_SIZE)
		&& g_tray.inter_v_y >= 0 && g_tray.inter_v_y <= g_sizeofmap * TILE_SIZE)
	{
		g_tray.xtocheck = g_tray.inter_v_x;
		g_tray.ytocheck = g_tray.inter_v_y;
		if (g_tray.ray_facingleft)
			g_tray.xtocheck--;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck) == 1)
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

void	verti_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	xi;
	float	yi;

	xi = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingright)
		xi += TILE_SIZE;
	yi = g_player.y + ((xi - g_player.x) * tan(ray_angle));
	deltax = TILE_SIZE;
	if (g_tray.ray_facingleft)
		deltax *= -1;
	deltay = TILE_SIZE * tan(ray_angle);
	if (g_tray.ray_facingdown && deltay < 0)
		deltay *= -1;
	if (g_tray.ray_facingup && deltay > 0)
		deltay *= -1;
	g_tray.inter_v_x = xi;
	g_tray.inter_v_y = yi;
	verti_iwall_collision(deltay, deltax);
}
