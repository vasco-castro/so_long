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

#include "../../include/so_long.h"

void	move_up(void)
{
	t_point	p;
	t_point	n;

	p = player()->position;
	n = p;
	n.y--;
	ft_printf("Trying to move UP from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_left(void)
{
	t_point	p;
	t_point	n;

	p.x = player()->position.x;
	p.y = player()->position.y;
	n = p;
	n.x--;
	ft_printf("Trying to move LEFT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_down(void)
{
	t_point	p;
	t_point	n;

	p.x = player()->position.x;
	p.y = player()->position.y;
	n = p;
	n.y++;
	ft_printf("Trying to move DOWN from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}

void	move_right(void)
{
	t_point	p;
	t_point	n;

	p.x = player()->position.x;
	p.y = player()->position.y;
	n = p;
	n.x++;
	ft_printf("Trying to move RIGHT from %d-%d to %d-%d\n", p.x, p.y, n.x, n.y);
	move(n);
}
