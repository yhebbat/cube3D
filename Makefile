SRC =	cub3d.c ft_atoi.c ft_check.c ft_draw.c ft_initialisation.c \
		ft_keys.c ft_render.c ft_split.c ft_utils.c ft_vert_horiz_inter.c \
 		get_next_line.c get_next_line_utils.c pars.c ray_cast_algo.c \
		ft_sprite.c ft_savecolors.c ft_savemap.c ft_savemap_utils.c \
		ft_saveresolution.c ft_savetext.c ft_initialisation2.c \
		ft_lstadd_back.c ft_lstnew.c get_text.c ft_render_utils.c \
		ft_free.c ft_substr.c ft_save_all.c ft_maperror.c ft_save.c


OBJECT = $(SRC:.c=.o)

NAME = cub3D.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -D BUFFER_SIZE=32 -O3
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc cub3d.c $(NAME) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o cub3D -O3


clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
