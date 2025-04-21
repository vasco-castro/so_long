/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 22:59:21 by vsoares-         ###   ########.fr       */
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
				draw_walls((t_position){x, y});
			else if (game()->map.map[y][x] == BACKGROUND)
				draw_background((t_position){x, y});
			else if (game()->map.map[y][x] == COLLECTIBLE)
				draw_collects((t_position){x, y});
			else if (game()->map.map[y][x] == PLAYER)
				draw_player((t_position){x, y});
			else if (game()->map.map[y][x] == EXIT)
				draw_exit((t_position){x, y});
			x--;
		}
		y--;
	}
}
