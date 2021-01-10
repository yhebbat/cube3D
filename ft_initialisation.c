# include "cub3d.h"
# include "get_next_line.h"

void	init_player()
{
	g_player.x = g_data.win_width / 2 - 64;
	g_player.y = g_data.win_height / 2;
	g_player.rotation_angle = PI / 2;
	g_player.rotation_speed = 3 * (PI / 180);
	g_player.move_speed = 5;
	g_player.angle = PI / 2;
}

void	init_move()
{
	g_player.walk_d = 0;
	g_player.turn_d = 0;
}

void	init_rays()
{	    
	g_tray.ray_facingup = 0;			
	g_tray.ray_facingdown  = 0;		
	g_tray.ray_facingright = 0;
	g_tray.ray_facingleft = 0;		
	g_tray.h_wallhit = 0;
	g_tray.h_wallhit_x = 0;
	g_tray.h_wallhit_y = 0;
	g_tray.h_wallcontent = 0;
	g_tray.inter_v_x = 0;
	g_tray.inter_v_y = 0;
	g_tray.inter_h_x = 0;
	g_tray.inter_h_y = 0;
	g_tray.v_wallhit = 0;
	g_tray.v_wallhit_x = 0;
	g_tray.v_wallhit_y = 0;
	g_tray.v_wallcontent = 0;
	g_tray.xtocheck = 0;
	g_tray.ytocheck = 0;
	g_tray.v_hit_distance = INT_MAX;
	g_tray.h_hit_distance = INT_MAX;
}

void	init_mlx()
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, g_data.win_width, g_data.win_height, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_data.win_width, g_data.win_height);
}