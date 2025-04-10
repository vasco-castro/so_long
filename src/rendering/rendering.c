/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/10 22:27:24 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_background(t_position position)
{
	ft_put_image(BACKGROUND_TEXTURE, position.x, position.y);
	// ft_printf("%s", game()->map.map);
}

static void	draw_walls(t_position position)
{
	ft_put_image(WALL_TEXTURE, position.x, position.y);
	// ft_printf("%s", game()->map.map);
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
	// ft_printf("%s", COLLECTIBLE_TEXTURE);
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
	ft_printf("SIZE OF MAP: %d - %d\n", x, y);
	while (y >= 0)
	{
		ft_printf("1-DEBUG Y:%d!\n", y);
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
		ft_printf("2-DEBUG Y:%d!\n", y);
		y--;
		ft_printf("3-DEBUG Y:%d!\n", y);
	}

	ft_printf("RENDERING MAP FINISHED!\n");

/*
	draw_walls((t_position){.x = 0, .y = 0});	draw_walls((t_position){.x = 0, .y = 1});	draw_walls((t_position){.x = 0, .y = 2});

	draw_walls((t_position){.x = 1, .y = 0});	draw_player((t_position){.x = 1, .y = 1});	draw_walls((t_position){.x = 1, .y = 2});

	draw_walls((t_position){.x = 2, .y = 0});	draw_walls((t_position){.x = 2, .y = 1});	draw_walls((t_position){.x = 2, .y = 2});



	draw_collects((t_position){.x = 3, .y = 3});
	draw_collects((t_position){.x = 4, .y = 4});
	draw_exit((t_position){.x = 5, .y = 5});
	draw_background((t_position){.x = 6, .y = 6}); */
}
