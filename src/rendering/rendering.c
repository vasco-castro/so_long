/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 13:41:20 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* TODO: Render collectibles count aswell,
 and render a background to fix overlap.
 Add an offset to write the string, and every game setting */
static void	render_moves_count(void)
{
	char	*moves_str;

	moves_str = ft_strjoin(ft_itoa(player()->moves), " moves");
	mlx_string_put(game()->mlx, game()->win, 16, WIN_H - 16, 0x00CC0000,
		moves_str);
	free(moves_str);
}

static void	render_position(t_point p, char tile)
{
	if (tile == BACKGROUND || tile == PLAYER)
		ft_put_image(BACKGROUND_TEXTURE, p);
	else if (tile == WALL)
		ft_put_image(WALL_TEXTURE, p);
	else if (tile == COLLECTIBLE)
		ft_put_image(COLLECTIBLE_TEXTURE, p);
	else if (tile == EXIT)
		ft_put_image(EXIT_TEXTURE, p);
}

/* TODO: Make calculation to render the map around the player,
 instead of being static
 Extra TODO: Implement player sprite animation. Using image frame_index */
void	render(void)
{
	int	x;
	int	y;

	y = map()->size.y - 1;
	while (y >= 0)
	{
		x = map()->size.x - 1;
		while (x >= 0)
		{
			// ft_printf(ON_CYAN"Rendering tile %c at position (%d, %d)!\n"RESET, map()->map[y][x], x, y);
			render_position((t_point){x, y}, map()->map[y][x]);
			x--;
		}
		y--;
	}
	// ft_printf(ON_CYAN"Rendering player asset!\n"RESET);
	ft_put_image(PLAYER_TEXTURE, player()->position);
	render_moves_count();
	ft_printf(BIBLUE "%t\n" RESET, map()->map);
}
