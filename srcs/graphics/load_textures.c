/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:33:55 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 20:39:40 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_textures(void)
{
	t_image	player;

	player = scale_sprite(PLAYER_TEXTURE, 0, 0);
	game()->textures.player = player;
	game()->textures.player_pos.x = WIN_W / TEXTURE_SIZE / 2;
	game()->textures.player_pos.y = WIN_H / TEXTURE_SIZE / 2;
	game()->textures.pineapple = scale_xpm(COLLECTIBLE_TEXTURE);
	game()->textures.water = scale_xpm(WALL_TEXTURE);
	game()->textures.sand = scale_xpm(BACKGROUND_TEXTURE);
	game()->textures.exit = scale_xpm(EXIT_TEXTURE);
}

void	clean_textures(void)
{
	if (game()->textures.player.img)
		mlx_destroy_image(game()->mlx, game()->textures.player.img);
	if (game()->textures.pineapple.img)
		mlx_destroy_image(game()->mlx, game()->textures.pineapple.img);
	if (game()->textures.water.img)
		mlx_destroy_image(game()->mlx, game()->textures.water.img);
	if (game()->textures.sand.img)
		mlx_destroy_image(game()->mlx, game()->textures.sand.img);
	if (game()->textures.exit.img)
		mlx_destroy_image(game()->mlx, game()->textures.exit.img);
}

/* t_textures	*textures(void)
{
	static t_textures	textures;

	return (&textures);
} */
