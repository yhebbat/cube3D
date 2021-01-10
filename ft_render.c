# include "cub3d.h"
# include "get_next_line.h"

void	render_ceiling(int start, int i)
{
	int	c;
	
	c = -1;
	while (++c < start)
	{
		my_mlx_pixel_put_3d(c, i, 0x0000ff);
	}
}

void	render_wall(int bot, int start, int i)
{
	start--;
	while (++start < bot)
	{
		my_mlx_pixel_put_3d(start, i, 0xa6a6a6);
	}
}

void	render_floor(int bot, int i)
{
	while (bot < g_data.win_height)
	{
		my_mlx_pixel_put_3d(bot, i, 0x4d0000);
		bot++;
	}
}

void	ft_render(int i)
{
	float	wall_h;
	int		dp;
	int		start;
	int		bot;


		dp = (g_data.win_width) / ( 2 * tan(FOV_ANGLE / 2));
		g_ray[i].distance *= cos(normalize_angle(g_ray[i].ray_angle - g_player.rotation_angle));
		wall_h = (TILE_SIZE / g_ray[i].distance) * dp;
		start = (g_data.win_height / 2) - (wall_h / 2);
		start = (start < 0) ? 0 : start;
		bot = (g_data.win_height / 2) + (wall_h / 2);
		bot = (bot > g_data.win_height) ? g_data.win_height : bot;
		render_ceiling(start, i);
		render_wall(bot, start, i);
		render_floor(bot, i);
}