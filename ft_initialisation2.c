/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:26:50 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:26:54 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

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
