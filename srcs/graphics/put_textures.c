/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:13:35 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 20:39:40 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static unsigned int	get_px(t_image *img, int x, int y)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return (0);
	return (*(unsigned int *)(img->addr + y * img->line + x * (img->bpp / 8)));
}

static void	put_px(t_image *img, int x, int y, unsigned int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	*(unsigned int *)(img->addr + y * img->line + x * (img->bpp / 8)) = color;
}

static void	scale_nearest(t_image *src, t_image *dst)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	y = 0;
	while (y < TEXTURE_SIZE)
	{
		sy = (y * src->h) / TEXTURE_SIZE;
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			sx = (x * src->w) / TEXTURE_SIZE;
			put_px(dst, x, y, get_px(src, sx, sy));
			x++;
		}
		y++;
	}
}

t_image	scale_xpm(char *path)
{
	t_image	src;
	t_image	dst;
	int		w;
	int		h;

	src.img = mlx_xpm_file_to_image(game()->mlx, path, &w, &h);
	if (!src.img)
		exit_so_long("Image error!");
	src.addr = mlx_get_data_addr(src.img, &src.bpp, &src.line, &src.endian);
	src.w = w;
	src.h = h;
	dst.img = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	if (!dst.img)
	{
		mlx_destroy_image(game()->mlx, src.img);
		exit_so_long("Image error!");
	}
	dst.addr = mlx_get_data_addr(dst.img, &dst.bpp, &dst.line, &dst.endian);
	dst.w = TEXTURE_SIZE;
	dst.h = TEXTURE_SIZE;
	scale_nearest(&src, &dst);
	mlx_destroy_image(game()->mlx, src.img);
	return (dst);
}

void	put_scaled(t_image *img, t_point p)
{
	if (img->img)
		mlx_put_image_to_window(game()->mlx, game()->win, img->img,
			p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
}
