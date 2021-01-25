/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:09:47 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/25 19:09:49 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		ft_getall(int fd)
{
	int		n;
	char	*line;
	char	*tmp;

	n = 1;
	while (n != 0)
	{
		n = get_next_line(fd, &line);
		ft_readfile(line);
		tmp = ft_strdup(line);
		if (ft_firstcharofmap(tmp))
		{
			if (g_mapindicator == 8)
				ft_lstadd_back(&g_file, ft_lstnew(line));
			else
			{
				free(tmp);
				free(line);
				break ;
			}
		}
		free(tmp);
		free(line);
	}
}
