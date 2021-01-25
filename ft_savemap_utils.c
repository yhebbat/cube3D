/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savemap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:37 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/22 18:15:38 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

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

void		ft_init_formap(void)
{
	g_sizeofmap = 0;
	g_biglen = 0;
	g_temp = g_file;
	g_str = NULL;
	g_nbp = 0;
}
