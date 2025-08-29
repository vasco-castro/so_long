/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:24:31 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:48:08 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_ismovevalid(t_point p)
{
	ft_printf("CHECKING P:%d-%d = %c\n", p.x, p.y, game()->map.map[p.y][p.x]);
	return (p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| game()->map.map[p.y][p.x] == WALL
	);
}

static void	update_move(t_point p)
{
	if (game()->map.map[p.y][p.x] == COLLECTIBLE)
	{
		ft_printf(CYAN "Got collectible in position: %d-%d\n" RESET, p.x, p.y);
		game()->map.player.collectibles++;
		ft_printf(CYAN "Total collectibles is: %d\n" RESET,
				  game()->map.player.collectibles);
		game()->map.map[p.y][p.x] = BACKGROUND;
	}
	else if (game()->map.map[p.y][p.x] == EXIT)
	{
		ft_printf(CYAN "Got to the exit in position: %d-%d\n" RESET, p.x, p.y);
		if (game()->map.player.collectibles < game()->map.collectibles)
		{
			ft_printf(RED "You need %d more collectibles to exit!\n" RESET,
					  game()->map.collectibles - game()->map.player.collectibles);
			return;
		}
		exit_successfully("Congratulations, you finish the game :)\n");
	}
}

void	move(t_point new_position)
{
	if (!ft_ismovevalid(new_position))
	{
		collect_move(new_position);
		exit_move(new_position);
		game()->map.player.position = new_position;
		game()->map.player.moves++;
		ft_printf(YELLOW "Moves: %d\n" RESET, game()->map.player.moves);
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}
