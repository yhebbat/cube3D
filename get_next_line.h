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

// MAP
char			**g_map;
t_list			*g_file;
t_list			*g_temp;
int				g_sizeofmap;
int				g_biglen;
char 			*g_str;

// MAP INDICATOR TO START THE INIT OF THE MAP
int				g_mapindicator;

// ...
t_data			g_data;
t_color			g_color[3];
t_textures		g_textures[5];

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				get_next_line(int fd, char **line);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);

void			ft_error(char *str);
void			ft_check_extention(char *str);
void			ft_check_xpm(char *str);
void			ft_data_init(void);
void			ft_check_resolution(char *str);
void			ft_color(char **color, char *str);
void			ft_check_colors(char *str);
void			ft_check_textures(char *str);
void			ft_check_file(char *str);

// Linked list AND MAP
void			free_list(void);
char			*spacer(char *buff, int size);
char			*space_filler(int size);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);

#endif
