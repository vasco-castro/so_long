/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:43:20 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render(void)
{
	int			x;
	int			y;

	ft_printf(BIBLUE "%t" RESET, game()->map.map);
	y = game()->map.size.y - 1;
	while (y >= 0)
	{
		x = game()->map.size.x - 1;
		while (x >= 0)
		{
			if (game()->map.map[y][x] == WALL)
				ft_put_image(WALL_TEXTURE, (t_point){x, y});
			else if (game()->map.map[y][x] == BACKGROUND)
				ft_put_image(BACKGROUND_TEXTURE, (t_point){x, y});
			else if (game()->map.map[y][x] == COLLECTIBLE)
				ft_put_image(COLLECTIBLE_TEXTURE, (t_point){x, y});
			else if (game()->map.map[y][x] == PLAYER)
				ft_put_image(PLAYER_TEXTURE, (t_point){x, y});
			else if (game()->map.map[y][x] == EXIT)
				ft_put_image(EXIT_TEXTURE, (t_point){x, y});
			x--;
		}
		y--;
	}
}
