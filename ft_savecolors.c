/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savecolors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:09 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/25 14:15:22 by yhebbat          ###   ########.fr       */
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
	{
		ft_free2(color);
		ft_error("Error\nProblem in the arguments of color");
	}
	i = -1;
	if (*(str + 1) != ' ')
		ft_error("Error\nun faut caractere apres le F ou C");
	while (++i < 3)
	{
		j = -1;
		while (color[i][++j])
		{
			if (color[i][j] < '0' || color[i][j] > '9')
				ft_error("Error\nLes couleurs Ne Sont Pas Bien Defini");
		}
	}
}

void		ft_nbrofdata(char **data, int i)
{
	int		j;
	int		r;

	j = 0;
	r = 0;
	if (i != 2)
	{
		ft_free2(data);
		printf("Error\nProblem in the color of the ceiling or floor\n");
		ft_error("if you make a space between colors 'RGB' delete it please");
	}
	while (data[1][j])
	{
		if (data[1][j] == ',')
			r++;
		j++;
	}
	if (r != 2)
		ft_error("Error\nin the colors");
}

void		ft_getclr(char *str, char **color)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if ((ft_atoi(color[i]) < 0) || (ft_atoi(color[i]) > 255))
			ft_error("Error\nLes couleurs Ne Sont Pas Bien Defini");
		else if (*str == 'F')
		{
			g_color[i].color_f = ft_atoi(color[i]);
		}
		else if (*str == 'C')
		{
			g_color[i].color_c = ft_atoi(color[i]);
		}
	}
	ft_free2(color);
}

void		ft_check_colors(char *str)
{
	char	**data;
	char	**color;
	int		i;

	i = 0;
	if (g_color[0].color_c != -1 && *str == 'C')
		ft_error("Error\ncolor of the ceiling is already filled");
	if (g_color[0].color_f != -1 && *str == 'F')
		ft_error("Error\ncolor of the floor is already filled");
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	ft_nbrofdata(data, i);
	color = ft_split(data[1], ',');
	ft_free2(data);
	ft_color(color, str);
	ft_getclr(str, color);
	g_mapindicator++;
}
