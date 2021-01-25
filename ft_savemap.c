/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:26 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:15:28 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

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
	ft_checkerror_map();
}
