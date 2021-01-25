/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maperror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:22:23 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/25 19:22:26 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_checkerror_map(void)
{
	int	j;
	int i;

	i = 0;
	while (++i < g_sizeofmap)
	{
		j = -1;
		while (++j < g_biglen)
		{
			// if (g_map[i][j] == 'N' || g_map[i][j] == 'S' 
			// 	|| g_map[i][j] == 'W' || g_map[i][j] == 'E')
					//g_nbp++;
			if (g_map[i][j] == '0' || g_map[i][j] == 'N' || g_map[i][j] == 'S' 
				|| g_map[i][j] == 'W' || g_map[i][j] == 'E' || g_map[i][j] == '2')
			{
				if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' ' 
					|| g_map[i][j + 1] == ' ' || g_map[i][j + 1] == ' ')
					ft_error("Error\ninvalid Map");
			}
			else if (g_map[i][j] != '0' && g_map[i][j] != 'N'
				&& g_map[i][j] != 'S' && g_map[i][j] != 'W' && g_map[i][j] != 'E'
				&& g_map[i][j] != '2' && g_map[i][j] != '1' && g_map[i][j] != ' ')
					ft_error("Error\ninvalid Map");
		}
		if (g_nbp != 1)
		{
			printf("%d\n", g_nbp);
			ft_error("Error\nMultiple or no players");
		}
	}
}