# include "cub3d.h"

void	check_angle(float angle)
{
	if (angle > PI)
		g_tray.ray_facingup = 1;
	else
		g_tray.ray_facingdown = 1;
	if (angle > PI / 2 && angle < 3 * PI / 2)
		g_tray.ray_facingleft = 1;
  	else
      g_tray.ray_facingright = 1;
}