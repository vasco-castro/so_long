/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:48:20 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/19 18:07:52 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Checks a single map tile for validity and updates metadata counters.
 *
 * This function validates the contents of a map cell at position `p`.
 * It increments the collectible, player, and exit counters as needed,
 * sets the player's position, and ensures map rules (walls, valid chars).
 *
 * @param p           The position in the map to check.
 * @param count_player Pointer to the player counter.
 * @param count_exit   Pointer to the exit counter.
 *
 * @throw Calls exit_so_long() if map rules are violated
 * (multiple players/exits, invalid chars, missing walls).
 */
static void	parse_check(t_point p)
{
	if (map()->map[p.y][p.x] == COLLECTIBLE)
		map()->pineapples++;
	else if (map()->map[p.y][p.x] == EXIT)
		map()->exit++;
	else if (map()->map[p.y][p.x] == PLAYER)
	{
		player()->position = (t_point){p.x, p.y};
		map()->player++;
	}
	else if (map()->map[p.y][p.x] != BACKGROUND && map()->map[p.y][p.x] != WALL)
		exit_so_long("Map has invalid characters!");
	if (p.y == 0 || p.y == map()->size.y - 1
		|| p.x == 0 || p.x == map()->size.x - 1)
		if (map()->map[p.y][p.x] != WALL)
			exit_so_long("Map is not surrounded by walls!");
}

/**
 * @brief Validates the entire map and updates metadata.
 *
 * Iterates through the map, checking each cell for validity using parse_check().
 * Ensures the map is rectangular, contains exactly one player and one exit,
 * and that all required rules are met.
 *
 * @throw Calls exit_so_long() if the map is invalid.
 */
void	validate_map(void)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map()->map[y])
	{
		if ((size_t) map()->size.x != ft_strlen(map()->map[y]))
			exit_so_long("Map size is incompatibly!");
		x = 0;
		while (map()->map[y][x])
		{
			parse_check((t_point){x, y});
			x++;
		}
		y++;
	}
	if (map()->exit != 1)
		exit_so_long("Map needs to have 1 and only 1 exit!");
	if (map()->player != 1)
		exit_so_long("Map needs to have 1 and only 1 player!");
	if (map()->pineapples < 1)
		exit_so_long("Map needs to have at least 1 collectible!");
}

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
