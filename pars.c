/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:50:08 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/09 15:31:05 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

void	ft_check_extention(char *str)
{
	int i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".cub", 5) != 0)
		ft_error("Error\nle fichier ne fini pas par .cub");
}

void	ft_check_xpm(char *str)
{
	int i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".xpm", 5) != 0)
		ft_error("Error\nle fichier ne fini pas par .xpm");
}

void	ft_data_init(void)
{
	int i;

	i = 0;
	g_data.win_width = -1;
	g_data.win_height = -1;
	while (i < 5)
	{
		g_textures[i].text_width = 0;
		g_textures[i].text_height = 0;
		g_textures[i].texture = "";
		i++;
	}
	i = 0;
	while (i < 3)
	{
		g_color[i].color_f = -1;
		g_color[i].color_c = -1;
		i++;
	}
}

void	ft_check_resolution(char *str)
{
	char	**data;
	int		i;
	int		j;

	i = 0;
	if (g_data.win_height != (-1) && g_data.win_width != (-1))
		ft_error("Error\nVous avez donner plus qu'une resolution");
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 3)
		ft_error("Error\nUn Probleme Dans La Resolution");
	i = 0;
	if (*(str + 1) == ' ')
	{
		while (++i < 3)
		{
			j = -1;
			while (data[i][++j])
			{
				if (data[i][j] < '0' || data[i][j] > '9')
					ft_error("La Resolution N'est Pas Bien Defini");
			}
		}
	}
	else
		ft_error("Error\nun faut caractere apres le R");
	g_data.win_height = ft_atoi(data[1]);
	g_data.win_width = ft_atoi(data[2]);
}

void	ft_color(char **color, char *str)
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

void	ft_check_colors(char *str)
{
	char	**data;
	char	**color;
	int		i;

	i = -1;
	/*while (++i < 3)
	{
		if (g_color[i].color_c != (-1) && g_color[i].color_f != (-1))
			ft_error("Error\nVous avez donner plus qu'une resolution");
	}*/
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
}

void	ft_check_textures(char *str)
{
	char	**data;
	int		i;

	i = 0;
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 2)
		ft_error("Error :o");
    ft_check_xpm(data[1]);
    if (*str == 'S' && *(str + 1) == 32)
        g_textures[S].texture = data[1];
    else if (*str == 'S' && *(str + 1) == 'O')
        g_textures[SO].texture = data[1];
    else if (*str == 'E' && *(str + 1) == 'A')
        g_textures[EA].texture = data[1];
    else if (*str == 'N' && *(str + 1) == 'O')
        g_textures[NO].texture = data[1];
    else if (*str == 'W' && *(str + 1) == 'E')
        g_textures[WE].texture = data[1];
	else
		ft_error("Error\nun faut caractere");
}

void	ft_check_file(char *str)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error("error file");
	while (get_next_line(fd, &line))
	{
		if (*line == 'R')
			ft_check_resolution(line);
		else if (*line == 'F' || *line == 'C')
			ft_check_colors(line);
		// else if (ft_strchr("NEWS", line[0]) && ft_strchr("EOA ", line[1]))
			// ft_check_textures(line);
		else if ((*line == 'N'||*line == 'W'||*line == 'E'||*line == 'S') &&  (*(line + 1) == 'E'||*(line + 1) == 'O'||*(line + 1) == 'A'||*(line + 1) == 32))
		    ft_check_textures(line);
		else if (*line != '\0')
			ft_error("error\nspace in the beginning of the line");
		free(line);
	}
}