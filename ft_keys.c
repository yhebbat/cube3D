/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:12:51 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 15:14:32 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int		key_press(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == W_KEY)
		g_player.walk_d = 1;
	if (key == S_KEY)
		g_player.walk_d = -1;
	if (key == LEFT_ARROW)
		g_player.turn_d = -1;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 1;
	if (key == D_KEY)
		g_player.walk_r = -1;
	if (key == A_KEY)
		g_player.walk_r = 1;
	return (0);
}

int		key_release(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == W_KEY)
		g_player.walk_d = 0;
	if (key == S_KEY)
		g_player.walk_d = 0;
	if (key == LEFT_ARROW)
		g_player.turn_d = 0;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 0;
	if (key == D_KEY)
		g_player.walk_r = 0;
	if (key == A_KEY)
		g_player.walk_r = 0;
	return (0);
}

int		ft_depends(void)
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	ft_move();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}
