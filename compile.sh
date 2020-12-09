cc -g3 -fsanitize=address -fast cub3d.c gnl/*.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=20
