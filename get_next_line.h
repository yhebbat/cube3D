/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:29:03 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/11 16:18:26 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "cub3d.h"

# define BUFFER_SIZE 32
# define S 0
# define NO 1
# define EA 2
# define SO 3
# define WE 4

typedef	struct	s_textures
{
	int			text_width;
	int			text_height;
	int			*text;
	char		*texture;
}				t_textures;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef	struct	s_data
{
	int			win_width;
	int			win_height;
}				t_data;

typedef	struct	s_color
{
	int			color_f;
	int			color_c;
}				t_color;

typedef struct	s_sprite
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	float		x;
	float		y;
	float		distance;
}				t_sprite;

/*
**MAP
*/
char			**g_map;
t_list			*g_file;
t_list			*g_temp;
int				g_sizeofmap;
int				g_biglen;
char 			*g_str;
int				g_nbp;
t_sprite		**g_sprite;
// int				g_ccolor;
// int				g_fcolor;

/*
**SPT
*/
t_sprite		**g_sprite;

// MAP INDICATOR TO START THE INIT OF THE MAP
int				g_mapindicator;

// ...
t_data			g_data;
t_color			g_color[3];
t_textures		g_textures[5];
int				g_sprite_c;

#endif
