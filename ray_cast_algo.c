#include "cub3d.h"

void	remplir_gray(float ray_angle, int strip_id)
{
	if (g_tray.v_hit_distance < g_tray.h_hit_distance)
	{
		g_ray[strip_id].distance = g_tray.v_hit_distance;
		g_ray[strip_id].wall_hitx = g_tray.v_wallhit_x;
		g_ray[strip_id].wall_hity = g_tray.v_wallhit_y;
		g_ray[strip_id].wall_hit_content = g_tray.v_wallcontent;
		g_ray[strip_id].was_hit_v = 1;
	}
	else
	{
		g_ray[strip_id].distance = g_tray.h_hit_distance;
		g_ray[strip_id].wall_hitx = g_tray.h_wallhit_x;
		g_ray[strip_id].wall_hity = g_tray.h_wallhit_y;
		g_ray[strip_id].wall_hit_content = g_tray.h_wallcontent;
		g_ray[strip_id].was_hit_v = 0;
	}
    g_ray[strip_id].ray_angle = ray_angle;
    g_ray[strip_id].ray_facingdown = g_tray.ray_facingdown;
    g_ray[strip_id].ray_facingup = g_tray.ray_facingup;
    g_ray[strip_id].ray_facingleft = g_tray.ray_facingleft;
    g_ray[strip_id].ray_facingright = g_tray.ray_facingright;
}

void	cast_ray(float ray_angle, int strip_id)
{
	ray_angle = normalize_angle(ray_angle);
	check_angle(ray_angle);
	horiz_inter(ray_angle);
	verti_inter(ray_angle);
	if (g_tray.h_wallhit)
		g_tray.h_hit_distance = distancebetweenpts(g_player.x, g_player.y, g_tray.h_wallhit_x, g_tray.h_wallhit_y);
	else
		g_tray.h_hit_distance = INT_MAX;
	if (g_tray.v_wallhit)
		g_tray.v_hit_distance = distancebetweenpts(g_player.x, g_player.y, g_tray.v_wallhit_x, g_tray.v_wallhit_y);
	else
		g_tray.v_hit_distance = INT_MAX;
	remplir_gray(ray_angle, strip_id);
}

void	cast_all_rays()
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = g_player.rotation_angle  - (FOV_ANGLE / 2);
	while (strip_id < NUM_RAYS)
	{
		init_rays();
		cast_ray(ray_angle, strip_id);
		ft_render(strip_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		draw_line_2(g_player.y, g_player.x, g_ray[strip_id].wall_hity, g_ray[strip_id].wall_hitx, ray_angle, 0xfffff);
		strip_id++;
	}
}