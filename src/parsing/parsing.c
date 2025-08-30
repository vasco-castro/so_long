/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 14:49:31 by vsoares-         ###   ########.fr       */
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
static void	parse_check(t_point p, size_t *count_player, size_t *count_exit)
{
	if (map()->map[p.y][p.x] == COLLECTIBLE)
		map()->collectibles++;
	else if (map()->map[p.y][p.x] == EXIT)
	{
		(*count_exit)++;
		if (*count_exit > 1)
			exit_so_long("Map has more than one exit!");
	}
	else if (map()->map[p.y][p.x] == PLAYER)
	{
		player()->position = (t_point){p.x, p.y};
		(*count_player)++;
		if (*count_player > 1)
			exit_so_long("Map has more than one player!");
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
static void	parse_map(void)
{
	size_t	x;
	size_t	y;
	size_t	count_player;
	size_t	count_exit;

	y = 0;
	count_exit = 0;
	count_player = 0;
	while (map()->map[y])
	{
		if (map()->size.x != ft_strlen(map()->map[y]))
			exit_so_long("Map size is incompatibly!");
		x = 0;
		while (map()->map[y][x])
		{
			parse_check((t_point){x, y}, &count_player, &count_exit);
			x++;
		}
		y++;
	}
	if (count_exit == 0)
		exit_so_long("Map has no exit!");
	if (count_player == 0)
		exit_so_long("Map has no player!");
}

/* Replace some code with ft_substr */
/**
 * @brief Reads a line from the map file, strips the newline, and allocates memory.
 *
 * Reads a line from the file descriptor, removes the trailing newline,
 * and returns a newly allocated string containing the line.
 *
 * @param fd File descriptor to read from.
 * @return Pointer to the allocated line string, or NULL on error/empty line.
 */
static char	*get_map_line(int fd)
{
	char	*line;
	char	*clean_line;
	char	*newline_pos;

	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		return (NULL);
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		clean_line = ft_substr(line, 0, (size_t)(newline_pos - line));
	else
		clean_line = ft_substr(line, 0, ft_strlen(line));
	free(line);
	return (clean_line);
}

/**
 * @brief Recursively reads all lines from the map file and allocates the map array.
 *
 * Reads each line of the map file, storing them in a dynamically allocated array.
 * Sets map width and height in the map struct.
 *
 * @param fd File descriptor to read from.
 * @param i  Current line index (used for recursion).
 * @return Pointer to the allocated array of map lines, or NULL on error.
 */
static char	**read_map(int fd, size_t i)
{
	char	*line;
	char	**result;

	line = get_map_line(fd);
	if (i == 0)
		map()->size.x = ft_strlen(line);
	if (!line && i == 0)
		return (NULL);
	else if (!line && i != 0)
	{
		map()->size.y = i;
		return (ft_calloc(sizeof(char *), (i + 1)));
	}
	result = read_map(fd, i + 1);
	result[i] = line;
	return (result);
}

/**
 * @brief Loads the map from a file and parses its contents into the map struct.
 *
 * Opens the map file, reads and allocates the map, then validates it.
 * On error, exits the program with an error message.
 * TODO: FIX FLOOD_FILL!!!!!
 *
 * @param map_path Path to the map file.
 * @return true if the map was loaded and parsed successfully, false otherwise.
 */
bool	get_map(char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		exit_so_long("Invalid file.\n");
	}
	map()->size.y = 0;
	map()->size.x = 0;
	map() -> map = read_map(fd, 0);
	close(fd);
	if (!map()->map)
		exit_so_long("Allocation went wrong!\n");
	ft_printf(BGREEN "Allocated map of size %d-%d successfully!\n"RESET"%t\n",
		map()->size.x, map()->size.y, map()->map);
	parse_map();
	// if (flood_fill(map()->map, player()->position))
		return (true);
	// else
	// 	exit_so_long("Map is not valid, no valid path to exit!");
}
