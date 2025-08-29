/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/04 19:43:12 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	render_position(t_point p, char tile)
{
	if (tile == 'F')
		ft_put_image(F_TEXTURE, p);
	else if (tile == WALL)
		ft_put_image(WALL_TEXTURE, p);
	else if (tile == BACKGROUND)
		ft_put_image(BACKGROUND_TEXTURE, p);
	else if (tile == COLLECTIBLE)
		ft_put_image(COLLECTIBLE_TEXTURE, p);
	else if (tile == EXIT)
		ft_put_image(EXIT_TEXTURE, p);
}

void	render(void)
{
	int	x;
	int	y;

	ft_printf(BIBLUE "%t" RESET, game()->map.map);
	y = game()->map.size.y - 1;
	while (y >= 0)
	{
		x = game()->map.size.x - 1;
		while (x >= 0)
		{
			render_position((t_point){x, y}, game()->map.map[y][x]);
			x--;
		}
		y--;
	}
	// TODO: Render player with sprite animation frame index!
	ft_put_image(PLAYER_TEXTURE, game()->map.player.position);
	// Render moves count, TODO: Render without overlapping cordinates!
	mlx_string_put(game()->mlx, game()->win, 10, 10, 0x00FFFFFF,
				   ft_itoa(game()->map.player.moves));
}
