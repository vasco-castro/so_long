/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 14:45:01 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Checks if a point is out of bounds, a wall, or already flooded.
 *
 * Determines if the given point is outside the map boundaries, is a wall,
 * or has already been marked as flooded ('F').
 *
 * @param map The map array to check against.
 * @param p   The point to check.
 * @return true if the point is invalid or already checked, false otherwise.
 */
static bool	ft_pointcheckedorinvalid(char *map[], t_point p)
{
	return (
		// p.x < 0 || p.y < 0 ||
		p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

/**
 * @brief Performs a flood fill search to validate map reachability.
 *
 * TODO: Floodfill until it founds all collectibles and the exit
 * TODO: Make a DEBUG version of the flood-fill with debug comments and rendering
 *
 * Recursively explores the map from point p, marking visited tiles as 'F'.
 * Stops if it reaches the exit. Used to check if all required tiles are reachable.
 *
 * @param map The map array to flood fill.
 * @param p   The starting point for the flood fill.
 * @return true if a valid path is found, false otherwise.
 */
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
