/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:24:31 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 20:39:40 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	update_move(t_point p)
{
	if (map()->map[p.y][p.x] == COLLECTIBLE)
	{
		debug(CYAN "Got pineapple in position: %d-%d\n" RESET, p.x, p.y);
		player()->pineapples++;
		debug(CYAN "Total pineapples is: %d\n" RESET,
			player()->pineapples);
		map()->map[p.y][p.x] = BACKGROUND;
	}
	else if (map()->map[p.y][p.x] == EXIT)
	{
		debug(CYAN "Got to the exit in position: %d-%d\n" RESET, p.x, p.y);
		if (player()->pineapples < map()->pineapples)
		{
			debug(RED "You need %d more pineapples to exit!\n" RESET,
				map()->pineapples - player()->pineapples);
			return ;
		}
		exit_successfully("Congratulations, you got all the pineapples :)");
	}
}

void	move(t_point p)
{
	debug("Trying to move from %d-%d to %d-%d\n",
		player()->position.x, player()->position.y, p.x, p.y);
	if (map()->map[p.y][p.x] != WALL)
	{
		update_move(p);
		player()->position = p;
		player()->moves++;
		debug(YELLOW "Moves: %d\n" RESET, player()->moves);
		render();
	}
	else
		debug(BRED "Invalid move!\n" RESET);
}
