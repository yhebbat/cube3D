#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "cub3d.h"

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
void			ft_data_init(void);
void			ft_error(char *str);
/*
**initialization
*/
void			init_player(void);
void			init_rays(void);
void			init_move(void);
void			init_mlx(void);
/*
**Linked list
*/
void			free_list(void);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);
/*
**SPRITE
*/
void			ft_sprite(void);
void			init_sprite(void);
/*
**parsing
*/
void			ft_getall(int fd);
char			*spacer(char *buff, int size);
char			*space_filler(int size);
void			ft_sizeofmap(void);
void			ft_readmap(void);
void			free_list(void);
int				ft_firstcharofmap(char *str);
void			ft_init_formap(void);
void			ft_check_resolution_error(char *str, char **data);
void			ft_check_resolution(char *str);
void			ft_color(char **color, char *str);
void			ft_check_colors(char *str);
void			ft_check_textures(char *str);
int				ft_condition_textures(char *str);
void    		ft_get_textures(void);
void    		get_no(void);
void			ft_check_file(char *str);
void			ft_check_extention(char *str);
void			ft_check_xpm(char *str);
void			ft_readfile(char *line);
void			ft_checkerror_map(void);
/*
**raycasting
*/
void			verti_inter(float ray_angle);
void			horiz_inter(float ray_angle);
void			cast_all_rays(void);
void			cast_ray(float ray_angle, int strip_id);
void			remplir_gray(float ray_angle, int strip_id);
/*
**rendering
*/
void			ft_render(int i);
void			render_floor(int bot, int i);
void			render_wall(int bot, int start, int i, float wall_h);
void			render_ceiling(int start, int i);
int				is_facing(int i);
int				rgb_to_int(int r, int g, int b);
/*
**drawing
*/
void			my_mlx_pixel_put(int y, int x, int color);
void			my_mlx_pixel_put_3d(int y, int x, int color);
void			draw_morba3(int j, int k, int color);
void			draw_line_of_player(void);
void			draw_player(void);
void			draw_line_2(float y, float x, float y1, float x1,
							float ray_angle, int color);
void			draw_line(int y0, int x0, int y1, int x1, int color);
/*
**moves
*/
int				key_release(int key);
int				key_press(int key);
void			ft_move(void);
/*
**utils
*/
float			normalize_angle(float	angle);
float			distancebetweenpts(float xd, float yd, float xf, float yf);
int				ft_depends(void);
void			check_angle(float angle);
int				wall_collision(float x, float y);
void			ft_jareb(void);
/*
**free
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_free2(char **p);

void    bmp_save(void);

#endif