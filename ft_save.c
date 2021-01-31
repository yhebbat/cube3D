/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:29:21 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/30 14:13:16 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		file_header(int fd)
{
	int		file_size;
	int		ofbits;

	ofbits = 54;
	file_size = ofbits + (g_data.win_height * g_data.win_width * 4);
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &ofbits, 4);
}

void		dib_header(int fd)
{
	int		bsize;
	int		biplan;
	int		imagesize;
	int		i;

	i = 16;
	bsize = 40;
	biplan = 1;
	imagesize = (g_data.win_height * g_data.win_width);
	write(fd, &bsize, 4);
	write(fd, &g_data.win_width, 4);
	write(fd, &g_data.win_height, 4);
	write(fd, &biplan, 2);
	write(fd, &g_mlx.bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &imagesize, 4);
	while (i--)
		write(fd, "\0", 1);
}

void		get_screen(int fd)
{
	int		x;
	int		y;

	y = g_data.win_height;
	while (--y > 0)
	{
		x = -1;
		while (++x < g_data.win_width)
		{
			write(fd, &g_mlx.addr[y * g_data.win_width + x], 3);
			write(fd, "\0", 1);
		}
	}
}

void		bmp_save(void)
{
	int		fd;

	if ((fd = open("./screenshot.bmp",
		O_CREAT | O_RDWR | O_NONBLOCK, 0666)) == -1)
		ft_error("Error\nIn the file of bitmap");
	g_mlx.img = mlx_new_window(g_mlx.mlx, g_data.win_width,
		g_data.win_height, "likelike");
	g_mlx.img = mlx_new_image(g_mlx.mlx, g_data.win_width, g_data.win_height);
	g_mlx.addr = (int *)mlx_get_data_addr(g_mlx.img,
			&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
	cast_all_rays();
	ft_sprite();
	file_header(fd);
	dib_header(fd);
	get_screen(fd);
	mlx_destroy_image(g_mlx.mlx, g_mlx.img);
	close(fd);
	exit(0);
}
