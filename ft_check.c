/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:11:56 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/20 16:50:05 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	check_angle(float angle)
{
	if (angle > PI)
		g_tray.ray_facingup = 1;
	else
		g_tray.ray_facingdown = 1;
	if (angle > PI / 2 && angle < 3 * PI / 2)
		g_tray.ray_facingleft = 1;
	else
		g_tray.ray_facingright = 1;
}
