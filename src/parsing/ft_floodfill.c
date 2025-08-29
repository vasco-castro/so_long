/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/04 19:54:15 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_pointcheckedorinvalid(char *map[], t_point p)
{
	return (
		// p.x < 0 || p.y < 0 ||
		p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

/* Check if it's surrounded by walls before flood_fill */
/* TODO: Floodfill until the amount of
	Collectibles is flooded and exit too */
/* TODO: Make a DEBUG version of the flood-fill with debug comments and rendering */
bool	flood_fill(char *map[], t_point p)
{
	char	c;

	// render(); //Only here to serve as debug for flood fill to actually view whats flooding
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
