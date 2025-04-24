/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:00:13 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:50:50 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(t_point np)
{
	t_point	op;

	op = game()->map.player.position;
	if (!ft_ismovevalid(np))
	{
		collect(np);
		exit_game(np);
		game()->map.map[op.y][op.x] = BACKGROUND;
		game()->map.map[np.y][np.x] = PLAYER;
		game()->map.player.position = np;
		render();
	}
	else
		ft_printf(BRED "Invalid move!\n" RESET);
}

void	move_up(void)
{
	t_point	p;
	t_point	n;

	p = game()->map.player.position;
	n = p;
	n.y--;
	ft_printf("Trying to move UP from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_left(void)
{
	t_point	p;
	t_point	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.x--;
	ft_printf("Trying to move LEFT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_down(void)
{
	t_point	p;
	t_point	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.y++;
	ft_printf("Trying to move DOWN from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_right(void)
{
	t_point	p;
	t_point	n;

	p.x = game()->map.player.position.x;
	p.y = game()->map.player.position.y;
	n = p;
	n.x++;
	ft_printf("Trying to move RIGHT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}
