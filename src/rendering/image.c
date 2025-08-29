/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:00:07 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:40:30 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Initializes t_image from an image pointer.
 * @param img Image pointer
 * @return Initialized t_image struct
 */
static t_image init_image(void *img)
{
	t_image im;

	im.image = img;
	im.address = mlx_get_data_addr(img, &im.bpp,
								   &im.size_line, &im.endian);
	return (im);
}

/**
 * @brief Copies a pixel from src to dst.
 * @param dst Destination image struct
 * @param dst_i Destination index
 * @param src Source image struct
 * @param src_i Source index
 */
static void copy_pixel(t_image dst, int dst_i, t_image src, int src_i)
{
	ft_memcpy(&dst.address[dst_i], &src.address[src_i], src.bpp / 8);
}

/**
 * @brief Handles one row of upscaling.
 */
static void upscale_row(t_image src, t_image dst, int src_w, int src_h,
						int dst_w, int dst_h, int y)
{
	int x;
	int src_x;
	int src_y;
	int src_i;
	int dst_i;

	x = 0;
	while (x < dst_w)
	{
		src_x = (x * src_w) / dst_w;
		src_y = (y * src_h) / dst_h;
		src_i = src_y * src.size_line + src_x * (src.bpp / 8);
		dst_i = y * dst.size_line + x * (dst.bpp / 8);
		copy_pixel(dst, dst_i, src, src_i);
		x++;
	}
}

/**
 * @brief Upscales a source image to a destination image of different size.
 * @param src Source image struct
 * @param dst Destination image struct
 * @param src_w Source image width
 * @param src_h Source image height
 * @param dst_w Destination image width
 * @param dst_h Destination image height
 */
static void upscale_image(t_image src, t_image dst, int src_w, int src_h,
						  int dst_w, int dst_h)
{
	int y;

	y = 0;
	while (y < dst_h)
	{
		upscale_row(src, dst, src_w, src_h, dst_w, dst_h, y);
		y++;
	}
}

/**
 * @brief Handles one row of sprite extraction.
 */
static void extract_sprite_row(t_image src, t_image dst, int x_offset,
							   int y_offset, int sprite_w, int y)
{
	int x;
	int src_i;
	int dst_i;

	x = 0;
	while (x < sprite_w)
	{
		src_i = (y + y_offset) * src.size_line + (x + x_offset) * (src.bpp / 8);
		dst_i = y * dst.size_line + x * (dst.bpp / 8);
		copy_pixel(dst, dst_i, src, src_i);
		x++;
	}
}

/**
 * @brief Extracts a sprite from a source image into a destination image.
 * @param src Source image struct
 * @param dst Destination image struct
 * @param x_offset X offset in source image
 * @param y_offset Y offset in source image
 * @param sprite_w Sprite width
 * @param sprite_h Sprite height
 */
static void extract_sprite(t_image src, t_image dst, int x_offset,
						   int y_offset, int sprite_w, int sprite_h)
{
	int y;

	y = 0;
	while (y < sprite_h)
	{
		extract_sprite_row(src, dst, x_offset, y_offset, sprite_w, y);
		y++;
	}
}

/**
 * @brief Puts a sprite on the window at position p,
 * 			using frame_index for animation.
 * @param texture Path to texture file
 * @param p Position to draw
 * @param frame_index Frame index for animation
 */
void ft_put_sprite(char *texture, t_point p, int frame_index)
{
	t_image src;
	t_image sprite;
	t_image upscaled;

	src.image = mlx_xpm_file_to_image(game()->mlx,
									  texture, &src.width, &src.height);
	src = init_image(src.image);
	if (!src.image)
		exit(2);
	sprite.image = mlx_new_image(game()->mlx, src.height, src.height);
	sprite = init_image(sprite.image);
	if (!sprite.image)
		exit(2);
	extract_sprite(src, sprite, src.height * frame_index, 0,
				   src.height, src.height);
	upscaled.image = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	upscaled = init_image(upscaled.image);
	if (!upscaled.image)
		exit(2);
	upscale_image(src, upscaled, src.height, src.height,
				  TEXTURE_SIZE, TEXTURE_SIZE);
	mlx_put_image_to_window(game()->mlx, game()->win, upscaled.image,
							TEXTURE_SIZE * p.x, TEXTURE_SIZE * p.y);
}

/**
 * @brief Puts an image on the window at position p.
 * @param texture Path to texture file
 * @param p Position to draw
 */
void ft_put_image(char *texture, t_point p)
{
	t_image src;
	t_image upscaled;

	src.image = mlx_xpm_file_to_image(game()->mlx, texture,
									  &src.width, &src.height);
	src = init_image(src.image);
	if (!src.image)
		exit(2);
	upscaled.image = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	upscaled = init_image(upscaled.image);
	if (!upscaled.image)
		exit(2);
	upscale_image(src, upscaled, src.height, src.height,
				  TEXTURE_SIZE, TEXTURE_SIZE);
	mlx_put_image_to_window(game()->mlx, game()->win, upscaled.image,
							TEXTURE_SIZE * p.x, TEXTURE_SIZE * p.y);
}
