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

#include "../so_long.h"

bool	ft_ismovevalid(t_point p)
{
	ft_printf("CHECKING P:%d-%d = %c\n", p.x, p.y, game()->map.map[p.y][p.x]);
	return (p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| game()->map.map[p.y][p.x] == WALL
	);
}

void    collect(t_point p)
{
    if (game()->map.map[p.y][p.x] == COLLECTIBLE)
    {
        ft_printf(CYAN "Got collectible in position: %d-%d\n" RESET, p.x, p.y);
        game()->map.player.collectibles++;
        ft_printf(CYAN "Total collectibles is: %d\n" RESET, 
            game()->map.player.collectibles);
    }
}

void    exit_game(t_point p)
{
    if (game()->map.map[p.y][p.x] == EXIT)
    {
        ft_printf(CYAN "Got to the exit in position: %d-%d\n" RESET, p.x, p.y);
        exit_successfully();
    }
}
