/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:22:33 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 21:23:19 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_position position)
{
	ft_put_image(BACKGROUND_TEXTURE, position.x, position.y);
}

void	draw_walls(t_position position)
{
	ft_put_image(WALL_TEXTURE, position.x, position.y);
}

void	draw_player(t_position position)
{
	ft_put_sprite(PLAYER_TEXTURE, position.x, position.y, 24);
}

void	draw_collects(t_position position)
{
	ft_put_image(COLLECTIBLE_TEXTURE, position.x, position.y);
}

void	draw_exit(t_position position)
{
	ft_put_image(EXIT_TEXTURE, position.x, position.y);
}

/* static void	draw_enemies(void)
{
	ft_printf("%s", game()->map.enemies);
} */
