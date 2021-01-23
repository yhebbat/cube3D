/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveresolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:46 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:15:47 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		ft_check_resolution_error(char *str, char **data)
{
	int		i;
	int		j;

	i = 0;
	if (*(str + 1) == ' ')
	{
		while (++i < 3)
		{
			j = -1;
			while (data[i][++j])
			{
				if (data[i][j] < '0' || data[i][j] > '9')
					ft_error("Error\nLa Resolution N'est Pas Bien Defini");
			}
		}
	}
	else
		ft_error("Error\nun faut caractere apres le R");
}

void		ft_check_resolution(char *str)
{
	char	**data;
	int		i;

	i = 0;
	if (g_data.win_height != (-1) && g_data.win_width != (-1))
		ft_error("Error\nVous avez donner plus qu'une resolution");
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 3)
	{
		ft_free(data, i);
		ft_error("Error\nUn Probleme Dans La Resolution");
	}
	ft_check_resolution_error(str, data);
	g_data.win_height = ft_atoi(data[2]);
	g_data.win_width = ft_atoi(data[1]);
	ft_free2(data);
	g_mapindicator++;
}
