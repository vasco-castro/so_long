/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfield.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 18:23:48 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	ft_pointcheckedorinvalid(char *map[], t_point p)
{
	return ( p.x < 0 || p.y < 0 ||
		p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

	/* Check if it's surrounded by walls before flood_field */
	/* TODO: Floodfill until the amount of
	 Collectibles is flooded and exit too */
bool	flood_fill(char *map[], t_point p)
{
	char	c;

	render();
	c = map[p.y][p.x];
	if (map[p.y][p.x] == EXIT)
		return (0);
	map[p.y][p.x] = 'F';
	if (!ft_pointcheckedorinvalid(map, (t_point){p.x, p.y - 1}))
		if (flood_fill(map, (t_point){p.x, p.y - 1}))
			return (1);
	if (!ft_pointcheckedorinvalid(map, (t_point){p.x, p.y + 1}))
		if (flood_fill(map, (t_point){p.x, p.y + 1}))
			return (1);
	if (!ft_pointcheckedorinvalid(map, (t_point){p.x - 1, p.y}))
		if (flood_fill(map, (t_point){p.x - 1, p.y}))
			return (1);
	if (!ft_pointcheckedorinvalid(map, (t_point){p.x + 1, p.y}))
		if (flood_fill(map, (t_point){p.x + 1, p.y}))
			return (1);
	map[p.y][p.x] = c;
	return (0);
}
