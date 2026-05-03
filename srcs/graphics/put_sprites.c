/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:14:50 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 22:13:21 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

/* -----------------------------------------------------------------
 *  Nearest-neighbour scaling of a SPRITE_W×SPRITE_H region
 * ----------------------------------------------------------------- */
static void	scale_region(t_image *src, int sx, int sy, t_image *dst)
{
	int	dx;
	int	dy;
	int	tx;
	int	ty;

	dy = 0;
	while (dy < TEXTURE_SIZE)
	{
		ty = (dy * PLAYER_SPRITE_SIZE) / TEXTURE_SIZE;
		dx = 0;
		while (dx < TEXTURE_SIZE)
		{
			tx = (dx * PLAYER_SPRITE_SIZE) / TEXTURE_SIZE;
			put_px(dst, dx, dy, get_px(src, sx + tx, sy + ty));
			dx++;
		}
		dy++;
	}
}

/* -----------------------------------------------------------------
 *  Load the whole sprite-sheet (call once, keep the returned image)
 * ----------------------------------------------------------------- */
static t_image	load_sheet(char *path)
{
	t_image	sheet;
	int		w;
	int		h;

	sheet.img = mlx_xpm_file_to_image(game()->mlx, path, &w, &h);
	if (!sheet.img)
		exit_so_long("Image error!");
	sheet.addr = mlx_get_data_addr(sheet.img, &sheet.bpp,
			&sheet.line, &sheet.endian);
	sheet.w = w;
	sheet.h = h;
	return (sheet);
}

/* -----------------------------------------------------------------
 *  Extract ONE sprite (sx,sy) and scale it to TEXTURE_SIZE
 * ----------------------------------------------------------------- */
t_image	scale_sprite(char *path, int sx, int sy)
{
	t_image	spr;
	t_image	sheet;

	sheet = load_sheet(path);
	if (!sheet.img)
		exit_so_long("Image error!");
	spr.img = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	if (!spr.img)
	{
		mlx_destroy_image(game()->mlx, sheet.img);
		exit_so_long("Image error!");
	}
	spr.addr = mlx_get_data_addr(spr.img, &spr.bpp, &spr.line, &spr.endian);
	spr.w = TEXTURE_SIZE;
	spr.h = TEXTURE_SIZE;
	scale_region(&sheet, sx, sy, &spr);
	mlx_destroy_image(game()->mlx, sheet.img);
	return (spr);
}
