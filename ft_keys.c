# include "cub3d.h"
# include "get_next_line.h"

int		key_press(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == UP_ARROW)
		g_player.walk_d = 1;
	if (key == DOWN_ARROW)
		g_player.walk_d = -1;
	if (key == LEFT_ARROW)
		g_player.turn_d = -1;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 1;
	return (0);
}

int		key_release(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	if (key == UP_ARROW)
		g_player.walk_d = 0;
	if (key == DOWN_ARROW)
		g_player.walk_d = 0;
	if (key == LEFT_ARROW)
		g_player.turn_d = 0;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 0;
	return (0);
}

int		ft_depends()
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	ft_move();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}