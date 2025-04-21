/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfield.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 22:43:41 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	ft_positioncheckedorinvalid(char *map[], t_position p)
{
	return (p.x < 0 || p.y < 0
		|| p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

	/* Check if it's surrounded by walls before flood_field */
	/* TODO: Floodfill until the amount of
	 Collectibles is flooded and exit too */
bool	flood_fill(char *map[], t_position p)
{
	char	c;

	c = map[p.y][p.x];
	if (map[p.y][p.x] == EXIT)
		return (0);
	map[p.y][p.x] = 'F';
	if (!ft_positioncheckedorinvalid(map, (t_position){p.x, p.y - 1}))
		if (flood_fill(map, (t_position){p.x, p.y - 1}))
			return (1);
	if (!ft_positioncheckedorinvalid(map, (t_position){p.x, p.y + 1}))
		if (flood_fill(map, (t_position){p.x, p.y + 1}))
			return (1);
	if (!ft_positioncheckedorinvalid(map, (t_position){p.x - 1, p.y}))
		if (flood_fill(map, (t_position){p.x - 1, p.y}))
			return (1);
	if (!ft_positioncheckedorinvalid(map, (t_position){p.x + 1, p.y}))
		if (flood_fill(map, (t_position){p.x + 1, p.y}))
			return (1);
	map[p.y][p.x] = c;
	return (0);
}
