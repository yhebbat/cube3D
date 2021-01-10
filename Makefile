SRC =	ft_atoi.c ft_check.c ft_draw.c ft_initialisation.c\
		ft_keys.c ft_render.c ft_split.c ft_utils.c ft_vert_horiz_inter.c\
 		get_next_line.c get_next_line_utils.c pars.c ray_cast_algo.c


OBJECT = $(SRC:.c=.o)

NAME = Cub3d.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -D BUFFER_SIZE=32 -O3 
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc cub3d.c $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o cub3d


clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all