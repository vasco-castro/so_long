/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/03 21:14:35 by vsoares-         ###   ########.fr       */
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
static bool	ft_isfillable(char *map[], t_point p)
{
	return (map[p.y][p.x] == WALL || map[p.y][p.x] == 'F');
}

/**
 * @brief Performs a flood fill search to validate map reachability.
 *
 * TODO: Make a DEBUG version of the flood-fill with debug comments and rendering
 *
 * Recursively explores the map from point p, marking visited tiles as 'F'.
 * Counts all exits and pineapples.
 * Used to check if all required tiles are reachable.
 *
 * @param map The map array to flood fill.
 * @param p   The starting point for the flood fill.
 */
void	flood_fill(char *map[], t_point p)
{
	if (map[p.y][p.x] == EXIT || map[p.y][p.x] == COLLECTIBLE)
		game()->map.filled++;
	map[p.y][p.x] = 'F';
	if (!ft_isfillable(map, (t_point){p.x, p.y - 1}))
		flood_fill(map, (t_point){p.x, p.y - 1});
	if (!ft_isfillable(map, (t_point){p.x, p.y + 1}))
		flood_fill(map, (t_point){p.x, p.y + 1});
	if (!ft_isfillable(map, (t_point){p.x - 1, p.y}))
		flood_fill(map, (t_point){p.x - 1, p.y});
	if (!ft_isfillable(map, (t_point){p.x + 1, p.y}))
		flood_fill(map, (t_point){p.x + 1, p.y});
}
