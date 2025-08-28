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

#include "../../include/so_long.h"

// source image is 24x24
static void upscale_image(void *src, void *dst, int src_w, int src_h, int dst_w, int dst_h)
{
    int bpp_src, line_len_src, endian_src;
    char *src_data = mlx_get_data_addr(src, &bpp_src, &line_len_src, &endian_src);

    int bpp_dst, line_len_dst, endian_dst;
    char *dst_data = mlx_get_data_addr(dst, &bpp_dst, &line_len_dst, &endian_dst);

    for (int y = 0; y < dst_h; y++) {
        for (int x = 0; x < dst_w; x++) {
            int src_x = (x * src_w) / dst_w;
            int src_y = (y * src_h) / dst_h;

            int src_i = src_y * line_len_src + src_x * (bpp_src / 8);
            int dst_i = y * line_len_dst + x * (bpp_dst / 8);

            ft_memcpy(&dst_data[dst_i], &src_data[src_i], bpp_src / 8);
        }
    }
}

static void extract_sprite(void *src_img, void *dst_img,
	int x_offset, int y_offset, int sprite_w, int sprite_h)
{
	int bpp_src, line_len_src, endian_src;
	char *src_data = mlx_get_data_addr(src_img, &bpp_src, &line_len_src, &endian_src);

	int bpp_dst, line_len_dst, endian_dst;
	char *dst_data = mlx_get_data_addr(dst_img, &bpp_dst, &line_len_dst, &endian_dst);

	for (int y = 0; y < sprite_h; y++) {
		for (int x = 0; x < sprite_w; x++) {

			int src_i = (y + y_offset) * line_len_src + (x + x_offset) * (bpp_src / 8);
			int dst_i = y * line_len_dst + x * (bpp_dst / 8);

			ft_memcpy(&dst_data[dst_i], &src_data[src_i], bpp_src / 8);
		}
	}
}

void	ft_put_sprite(char *texture, t_point p, int frame_index)
{
	t_image src,sprite;

	// TODO: PROPERLY DESTROY AND FREE IMAGES IN GENERAL
	src.image = mlx_xpm_file_to_image(game()->mlx, texture, &src.width, &src.height);
	if(!src.image) exit(2);

	sprite.image = mlx_new_image(game()->mlx, src.height, src.height);
	if(!sprite.image) exit(2);

	extract_sprite(src.image, sprite.image, src.height * frame_index, 0, src.height, src.height);

	// TODO: DESTROY AND FREE SOURCE IMAGE
	t_image upscaled;
	upscaled.image = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	if(!upscaled.image) exit(2);
	upscale_image(src.image, upscaled.image, src.height, src.height, TEXTURE_SIZE, TEXTURE_SIZE);

	mlx_put_image_to_window(game()->mlx, game()->win, upscaled.image, TEXTURE_SIZE * p.x, TEXTURE_SIZE * p.y);
}

void	ft_put_image(char *texture, t_point p)
{
	t_image src;

	src.image = mlx_xpm_file_to_image(game()->mlx, texture, &src.width, &src.height);
	if(!src.image) exit(2);

	// TODO: DESTROY AND FREE SOURCE IMAGE
	t_image upscaled;
	upscaled.image = mlx_new_image(game()->mlx, TEXTURE_SIZE, TEXTURE_SIZE);
	if(!upscaled.image) exit(2);
	upscale_image(src.image, upscaled.image, src.height, src.height, TEXTURE_SIZE, TEXTURE_SIZE);
	// TODO: PROPERLY DESTROY AND FREE IMAGES IN GENERAL

	mlx_put_image_to_window(game()->mlx, game()->win, upscaled.image, TEXTURE_SIZE * p.x, TEXTURE_SIZE * p.y);
}
