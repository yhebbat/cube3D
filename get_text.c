/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:29:23 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 16:21:08 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void		get_ea(void)
{
	void	*img;

	if (!(img = mlx_xpm_file_to_image(g_mlx.mlx, g_textures[EA].texture,
					&g_textures[EA].text_width, &g_textures[EA].text_height)))
		ft_error("the texture of the east is not well defined");
	g_textures[EA].text = (int*)mlx_get_data_addr(img, &g_mlx.bpp,
			&g_mlx.size_line, &g_mlx.endian);
}

void		get_so(void)
{
	void	*img;

	if (!(img = mlx_xpm_file_to_image(g_mlx.mlx, g_textures[SO].texture,
					&g_textures[SO].text_width, &g_textures[SO].text_height)))
		ft_error("the texture of the south is not well defined");
	g_textures[SO].text = (int*)mlx_get_data_addr(img, &g_mlx.bpp,
			&g_mlx.size_line, &g_mlx.endian);
}

void		get_we(void)
{
	void	*img;

	if (!(img = mlx_xpm_file_to_image(g_mlx.mlx, g_textures[WE].texture,
					&g_textures[WE].text_width, &g_textures[WE].text_height)))
		ft_error("the texture of the west is not well defined");
	g_textures[WE].text = (int*)mlx_get_data_addr(img, &g_mlx.bpp,
			&g_mlx.size_line, &g_mlx.endian);
}

void		get_no(void)
{
	void	*img;

	if (!(img = mlx_xpm_file_to_image(g_mlx.mlx, g_textures[NO].texture,
					&g_textures[NO].text_width, &g_textures[NO].text_height)))
		ft_error("Error\nthe texture of the north is not well defined");
	g_textures[NO].text = (int*)mlx_get_data_addr(img, &g_mlx.bpp,
			&g_mlx.size_line, &g_mlx.endian);
}

void		ft_get_textures(void)
{
	get_no();
	get_so();
	get_ea();
	get_we();
}
