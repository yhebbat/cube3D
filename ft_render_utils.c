/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:34:28 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:34:30 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int			is_facing(int i)
{
	int		t;

	t = 0;
	if (g_ray[i].ray_facingup && !g_ray[i].was_hit_v)
		t = 1;
	if (g_ray[i].ray_facingdown && !g_ray[i].was_hit_v)
		t = 3;
	else if (g_ray[i].ray_facingright && g_ray[i].was_hit_v)
		t = 2;
	else if (g_ray[i].ray_facingleft && g_ray[i].was_hit_v)
		t = 4;
	return (t);
}

int			rgb_to_int(int r, int g, int b)
{
	int		k;

	k = (256 * 256 * r) + (256 * g) + b;
	return (k);
}
