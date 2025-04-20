/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/10 22:33:40 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_background(t_position position)
{
	ft_put_image(BACKGROUND_TEXTURE, position.x, position.y);
}

static void	draw_walls(t_position position)
{
	ft_put_image(WALL_TEXTURE, position.x, position.y);
}

static void	draw_player(t_position position)
{
	ft_put_sprite(PLAYER_TEXTURE, position.x, position.y, 24);
}

/* static void	draw_enemies(void)
{
	ft_printf("%s", game()->map.enemies);
} */

static void	draw_collects(t_position position)
{
	ft_put_image(COLLECTIBLE_TEXTURE, position.x, position.y);
}

static void	draw_exit(t_position position)
{
	ft_put_image(EXIT_TEXTURE, position.x, position.y);
}

void	render(void)
{
	int	x;
	int y;

	x = game()->map.size.x - 1;
	y = game()->map.size.y - 1;
	while (y >= 0)
	{
		x = game()->map.size.x - 1;
		while (x >= 0)
		{
			ft_printf("PARSING: %c\n", game()->map.map[y][x]);
			if (game()->map.map[y][x] == WALL) draw_walls((t_position){x,y});
			else if (game()->map.map[y][x] == BACKGROUND) draw_background((t_position){x,y});
			else if (game()->map.map[y][x] == 'F') draw_background((t_position){x,y});
			else if (game()->map.map[y][x] == COLLECTIBLE) draw_collects((t_position){x,y});
			else if (game()->map.map[y][x] == PLAYER) draw_player((t_position){x,y});
			else if (game()->map.map[y][x] == EXIT) draw_exit((t_position){x,y});
			x--;
		}
		y--;
	}
}
