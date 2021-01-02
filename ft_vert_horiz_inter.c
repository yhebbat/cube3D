# include "cub3d.h"

void	horiz_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Yi = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingdown)
		Yi += TILE_SIZE;
	Xi = g_player.x + ((Yi - g_player.y) / tan(ray_angle));
	deltay = TILE_SIZE;
	if (g_tray.ray_facingup)
		deltay *= -1;
	deltax = TILE_SIZE / tan(ray_angle);
	if (g_tray.ray_facingright && deltax < 0)
		deltax *= -1;
	if (g_tray.ray_facingleft && deltax > 0)
		deltax *= -1;
	g_tray.inter_h_x = Xi;
	g_tray.inter_h_y = Yi;
	if (g_tray.ray_facingup)
		g_tray.inter_h_y--;
	while (g_tray.inter_h_x >= 0 && g_tray.inter_h_x <= WIN_WIDTH && g_tray.inter_h_y >= 0 && g_tray.inter_h_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_h_x;
		g_tray.ytocheck = g_tray.inter_h_y;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck))
		{
			g_tray.h_wallhit_x = g_tray.inter_h_x;
			g_tray.h_wallhit_y = g_tray.inter_h_y;
			g_tray.h_wallhit = 1;
			break ;
		}
		else
		{
			g_tray.inter_h_x += deltax;
			g_tray.inter_h_y += deltay;
		}
	}		
}

void	verti_inter(float ray_angle)
{
	float	deltax;
	float	deltay;
	float	Xi;
	float	Yi;

	Xi = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (g_tray.ray_facingright)
		Xi += TILE_SIZE;
	Yi = g_player.y + ((Xi - g_player.x) * tan(ray_angle));
	deltax = TILE_SIZE;
	if (g_tray.ray_facingleft)
		deltax *= -1;
	deltay = TILE_SIZE * tan(ray_angle);
	if (g_tray.ray_facingdown && deltay < 0)
		deltay *= -1;
	if (g_tray.ray_facingup && deltay > 0)
		deltay *= -1;
	g_tray.inter_v_x = Xi;
	g_tray.inter_v_y = Yi;
	if (g_tray.ray_facingleft)
		g_tray.inter_v_x--;
	while (g_tray.inter_v_x >= 0 && g_tray.inter_v_x <= WIN_WIDTH && g_tray.inter_v_y >= 0 && g_tray.inter_v_y <= WIN_HEIGHT)
	{
		g_tray.xtocheck = g_tray.inter_v_x;
		g_tray.ytocheck = g_tray.inter_v_y;
		if (wall_collision(g_tray.xtocheck, g_tray.ytocheck))
		{
			g_tray.v_wallhit_x = g_tray.inter_v_x;
			g_tray.v_wallhit_y = g_tray.inter_v_y;
			g_tray.v_wallhit = 1;
			break ;
		}
		else
		{
			g_tray.inter_v_x += deltax;
			g_tray.inter_v_y += deltay;
		}
	}
}