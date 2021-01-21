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
		ft_error("Error\nUn Probleme Dans La Resolution");
	ft_check_resolution_error(str, data);
	g_data.win_height = ft_atoi(data[2]);
	g_data.win_width = ft_atoi(data[1]);
	g_mapindicator++;
}

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

/*
 **traiter la multiplication des couleurs
*/

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

void		ft_check_textures(char *str)
{
	char	**data;
	int		i;

	i = 0;
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 2)
		ft_error("Error :o");
	if (*str == 'S' && *(str + 1) == 32)
		g_textures[S].texture = ft_strdup(data[1]);
	else if (*str == 'S' && *(str + 1) == 'O')
		g_textures[SO].texture = ft_strdup(data[1]);
	else if (*str == 'E' && *(str + 1) == 'A')
		g_textures[EA].texture = ft_strdup(data[1]);
	else if (*str == 'N' && *(str + 1) == 'O')
		g_textures[NO].texture = ft_strdup(data[1]);
	else if (*str == 'W' && *(str + 1) == 'E')
		g_textures[WE].texture = ft_strdup(data[1]);
	else
		ft_error("Error\nun faut caractere");
	g_mapindicator++;
}

int			ft_condition_textures(char *str)
{
	if (*str == 'N' && *(str + 1) == 'O')
		return (1);
	if (*str == 'S' && *(str + 1) == 'O')
		return (1);
	if (*str == 'W' && *(str + 1) == 'E')
		return (1);
	if (*str == 'E' && *(str + 1) == 'A')
		return (1);
	if (*str == 'S' && *(str + 1) == ' ')
		return (1);
	return (0);
}

void		ft_readfile(char *line)
{
	if (*line == 'R'/* && *(line + 1) == ' '*/)
		ft_check_resolution(line);
	else if ((*line == 'F' || *line == 'C') && *(line + 1) == ' ')
		ft_check_colors(line);
	else if (ft_condition_textures(line))
		ft_check_textures(line);
}

void		free_list(void)
{
	while (g_file != NULL)
	{
		g_temp = g_file;
		g_file = g_file->next;
		free(g_temp->content);
		free(g_temp);
	}
}

int			ft_firstcharofmap(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		else
			break ;
	}
	return (0);
}

char		*spacer(char *buff, int size)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	str[i] = ' ';
	i++;
	j = 0;
	while (buff[j])
	{
		str[i] = buff[j];
		j++;
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*space_filler(int size)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		ft_init_formap(void)
{
	g_sizeofmap = 0;
	g_biglen = 0;
	g_temp = g_file;
	g_str = NULL;
}

void		ft_sizeofmap(void)
{
	while (g_temp)
	{
		g_str = g_temp->content;
		if (ft_firstcharofmap(g_str))
		{
			g_sizeofmap++;
			if (ft_strlen(g_str) > (size_t)g_biglen)
				g_biglen = ft_strlen(g_str);
		}
		g_temp = g_temp->next;
	}
}

void		ft_readmap(void)
{
	int		i;

	ft_init_formap();
	ft_sizeofmap();
	g_sizeofmap += 2;
	g_biglen += 2;
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_sizeofmap + 1))))
		return ;
	g_map[0] = space_filler(g_biglen);
	g_temp = g_file;
	g_str = NULL;
	i = 1;
	while (g_temp)
	{
		g_str = g_temp->content;
		if (ft_firstcharofmap(g_str))
			g_map[i++] = spacer(g_str, g_biglen);
		g_temp = g_temp->next;
	}
	g_map[i++] = space_filler(g_biglen);
	g_map[i] = NULL;
	free_list();
}

void		ft_check_file(char *str)
{
	int		fd;
	int		n;
	char	*line;

	g_mapindicator = 0;
	n = 1;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error("error file");
	while (n != 0)
	{
		n = get_next_line(fd, &line);
		ft_readfile(line);
		ft_lstadd_back(&g_file, ft_lstnew(line));
		free(line);
	}
	if (g_mapindicator == 8)
		ft_readmap();
	else
		ft_error("Error\ndata no completed");
}
