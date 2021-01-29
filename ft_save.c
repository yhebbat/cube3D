/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:29:21 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/29 15:29:23 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "get_next_line.h"

void	init_header(unsigned char *fileheader,unsigned char *infoheader)
{
	int		filesize;

	filesize = 54 + 3*g_data.win_width*g_data.win_height;
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	infoheader[4] = (unsigned char)(g_data.win_width);
	infoheader[5] = (unsigned char)(g_data.win_width >> 8);
	infoheader[6] = (unsigned char)(g_data.win_width >> 16);
	infoheader[7] = (unsigned char)(g_data.win_width >> 24);
	infoheader[8] = (unsigned char)(g_data.win_height);
	infoheader[9] = (unsigned char)(g_data.win_height >> 8);
	infoheader[10] = (unsigned char)(g_data.win_height >> 16);
	infoheader[11] = (unsigned char)(g_data.win_height >> 24);
}

void	write_bmp_data(int fd, char *bitmap)
{
	int		padding_size;
	int		i;
	int		j;

	padding_size = (4 - (g_data.win_width * 3) % 4) % 4;
	i = -1;
	while (++i < g_data.win_height)
	{
		j = -1;
		while (++j < g_data.win_width)
			write(fd, g_mlx.data + (j + (g_data.win_height - i - 1) * g_data.win_width), 3);
		write(fd, bitmap, padding_size);
	}
}

void    bmp_save(void)
{
	static unsigned char	fileheader[14] =
	{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	static unsigned char	infoheader[40] =
	{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	static char				bitmap[3] =
	{0, 0, 0};
	int						fd;

	init_header(fileheader, infoheader);
	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	write(fd, fileheader, 14);
	write(fd, infoheader, 40);
	write_bmp_data(fd, bitmap);
	close(fd);
}