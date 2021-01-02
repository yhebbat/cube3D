SRC = cub3d.c ft_utils.c ft_initialisation.c ft_render.c \
		ft_keys.c ft_draw.c ft_check.c ft_vert_horiz_inter.c \
		ray_cast_algo.c


OBJECT = $(SRC:.c=.o)

NAME = Cub3d.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -O3
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all