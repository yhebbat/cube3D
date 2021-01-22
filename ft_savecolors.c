/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savecolors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:09 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:15:12 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		ft_color(char **color, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (color[i])
		i++;
	if (i != 3)
		ft_error("Error\nProblem in the arguments of color");
	i = 0;
	if (*(str + 1) == ' ')
	{
		while (i < 3)
		{
			j = 0;
			while (color[i][j])
			{
				if (color[i][j] < '0' || color[i][j] > '9')
					ft_error("Les Des couleurs Ne Sont Pas Bien Defini");
				j++;
			}
			i++;
		}
	}
	else
		ft_error("Error\nun faut caractere apres le F ou C");
}

void		ft_check_colors(char *str)
{
	char	**data;
	char	**color;
	int		i;

	i = 0;
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 2)
		ft_error("Error\nProblem in the color of the ceiling or floor");
	color = ft_split(data[1], ',');
	ft_color(color, str);
	i = 0;
	while (i < 3)
	{
		if ((ft_atoi(color[i]) < 0) || (ft_atoi(color[i]) > 255))
			ft_error("Les couleurs Ne Sont Pas Bien Defini");
		else if (*str == 'F')
			g_color[i].color_f = ft_atoi(color[i]);
		else
			g_color[i].color_c = ft_atoi(color[i]);
		i++;
	}
	g_mapindicator++;
}
