/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:00:13 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 23:39:11 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static bool	ft_ismovevalid(t_position p)
{
	ft_printf("CHECKING P:%d-%d = %c\n", p.x, p.y, game()->map.map[p.y][p.x]);
	return (p.x < 0 || p.y < 0
		|| p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| game()->map.map[p.y][p.x] == WALL
	);
}

void	move_up(void)
{
	t_position	p;
	t_position	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.y--;
	ft_printf("Trying to move UP from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	if (!ft_ismovevalid(n))
	{
		game()->map.map[p.y][p.x] = '0';
		game()->map.map[n.y][n.x] = 'P';
		game()->map.player.position = n;
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}

void	move_left(void)
{
	t_position	p;
	t_position	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.x--;
	ft_printf("Trying to move LEFT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	if (!ft_ismovevalid(n))
	{
		game()->map.map[p.y][p.x] = '0';
		game()->map.map[n.y][n.x] = 'P';
		game()->map.player.position = n;
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}

void	move_down(void)
{
	t_position	p;
	t_position	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.y++;
	ft_printf("Trying to move DOWN from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	if (!ft_ismovevalid(n))
	{
		game()->map.map[p.y][p.x] = '0';
		game()->map.map[n.y][n.x] = 'P';
		game()->map.player.position = n;
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}

void	move_right(void)
{
	t_position	p;
	t_position	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.x++;
	ft_printf("Trying to move RIGHT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	if (!ft_ismovevalid(n))
	{
		game()->map.map[p.y][p.x] = '0';
		game()->map.map[n.y][n.x] = 'P';
		game()->map.player.position = n;
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}
