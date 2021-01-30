/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:50:08 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 18:00:04 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

void		ft_check_extention(char *str)
{
	int		i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".cub", 5) != 0)
		ft_error("Error\nle fichier ne fini pas par .cub");
}

/*
**void	ft_check_xpm(char *str)
**{
**int i;
**i = ft_strlen(str) - 4;
**if (ft_strncmp(str + i, ".xpm", 5) != 0)
** ft_error("Error\nle fichier ne fini pas par .xpm");
**}
*/

void		ft_data_init(void)
{
	int		i;

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

void		ft_readfile(char *line)
{
	int		i;

	i = 0;
	if (line[i] == 32)
	{
		while (line[i] == ' ')
			i++;
		if (((line[i] != 0 && line[i] != '1') && g_mapindicator == 8)
			|| (line[i] != '\0' && line[i] != '1'))
			ft_error("Error\nfile .cub invalid");
	}
	if (*line == 'R')
		ft_check_resolution(line);
	else if ((*line == 'F' || *line == 'C') && *(line + 1) == ' ')
		ft_check_colors(line);
	else if (ft_condition_textures(line))
		ft_check_textures(line);
}

void		ft_check_file(char *str)
{
	int		fd;

	g_mapindicator = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error("error file");
	ft_getall(fd);
	if (g_mapindicator == 8)
		ft_readmap();
	else
		ft_error("Error\ndata no completed");
}
