/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:16:01 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:16:02 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		ft_datatxtnbr(char **data, int i)
{
	if (i != 2)
	{
		ft_free2(data);
		ft_error("Error\nprobleme in the path of textures");
	}
}

void		ft_check_textures(char *str)
{
	char	**data;
	int		i;

	i = 0;
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	ft_datatxtnbr(data, i);
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
	ft_free2(data);
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
