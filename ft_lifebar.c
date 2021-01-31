/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lifebar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:01:53 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/31 18:05:17 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_lifebar(void)
{
	int		x;
	int		y;
	int		tab[2];
	void	*bar;

	x = 10;
	y = 10;
	tab[0] = 0;
	tab[1] = 0;
	if (!(bar = mlx_xpm_file_to_image(g_mlx.mlx, "./texture/do.xpm",
					&tab[0], &tab[1])))
		ft_error("Error\nlife bar problem");
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, bar, 0, 0);
}
