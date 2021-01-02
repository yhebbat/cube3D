# include "cub3d.h"

void	draw_line(int Y0, int X0, int Y1, int X1, int color)
{
	int		dx = X1 - X0;
	int		dy = Y1 - Y0;
	int		i = 0;
	int		steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float	Xinc = dx / (float)steps;
	float	Yinc = dy / (float)steps;
	float	X = X0;
	float	Y = Y0;
	while (i <= steps)
	{
		my_mlx_pixel_put(Y, X, color);
		X += Xinc;
		Y += Yinc;
		i++;
	}
}

void	draw_line_2(float y, float x, float y1, float x1,float ray_angle, int color)
{
	int dist = distancebetweenpts(x, y, x1, y1);
	float i;
	float j = y;
	float c = x;

	i = 0;
	ray_angle = normalize_angle(ray_angle);
	while (i < dist)
	{
		x = c + (i * cos(ray_angle));
		y = j + (i * sin(ray_angle));
		my_mlx_pixel_put(y, x, color);
		i++;
	}
}

int		draw_player()
{

    float   j;
    float   zb;
    float   x;
    float   y;

    j = RAYON;
    while (j > 0)
    {
        zb = 0;
        while (zb <= 360)
        {
            x = g_player.x + j * cos(zb * g_player.angle);
            y = g_player.y + j * sin(zb * g_player.angle);
            my_mlx_pixel_put(y, x, 0xff0000);
            zb += 0.1;
        }
        j--;
    }
	draw_line_of_player();
	return (0);
}

void	draw_line_of_player()
{
	int		k;
	float	y;
	float	x;

	k = PLAYERLINE;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	while (k)
	{
		y = g_player.y + sin(g_player.rotation_angle) * k;
		x = g_player.x + cos(g_player.rotation_angle) * k;
		my_mlx_pixel_put(y, x, 0xff0000);
		k--;
	}
}

void	draw_morba3(int j, int k, int color)
{
	int		x;
	int		y;
	int		c;

	y = j + 64;
	x = k + 64;
	while (j < y)
	{
		c = k;
		while(c < x)
		{
			my_mlx_pixel_put(j, c, color);
			c++;
		}
		j++;
	}
}