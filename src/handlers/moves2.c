/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:24:31 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 13:24:23 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	update_move(t_point p)
{
	if (map()->map[p.y][p.x] == COLLECTIBLE)
	{
		ft_printf(CYAN "Got collectible in position: %d-%d\n" RESET, p.x, p.y);
		player()->collectibles++;
		ft_printf(CYAN "Total collectibles is: %d\n" RESET,
			player()->collectibles);
		map()->map[p.y][p.x] = BACKGROUND;
	}
	else if (map()->map[p.y][p.x] == EXIT)
	{
		ft_printf(CYAN "Got to the exit in position: %d-%d\n" RESET, p.x, p.y);
		if (player()->collectibles < map()->collectibles)
		{
			ft_printf(RED "You need %d more collectibles to exit!\n" RESET,
				map()->collectibles - player()->collectibles);
			return ;
		}
		exit_successfully("Congratulations, you finish the game :)\n");
	}
}

void	move(t_point p)
{
	if (map()->map[p.y][p.x] != WALL)
	{
		update_move(p);
		player()->position = p;
		player()->moves++;
		ft_printf(YELLOW "Moves: %d\n" RESET, player()->moves);
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}
