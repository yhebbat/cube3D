cc -g3 -fsanitize=address -fast lbft/*.c cub3d.c gnl/get_next_line.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=20
