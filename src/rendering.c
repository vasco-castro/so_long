/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/23 18:27:12 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_background(void)
{
	printf("%s", game()->map.map);
}

static void	draw_map(void)
{
	printf("%s", game()->map.map);
}

static void	draw_player(void)
{
	printf("%s", game()->map.player);
}

/* static void	draw_enemies(void)
{
	printf("%s", game()->map.enemies);
} */

static void	draw_moves(void)
{
	printf("%s", game()->map.player.moves);
}

void	render(void)
{
	draw_background();
	draw_map();
	draw_player();
	draw_moves();
}
