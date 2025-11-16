/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/16 19:53:37 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Reads a line from the map file, strips the newline,
 * and allocates memory.
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
	if (!line)
		return (NULL);
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		clean_line = ft_substr(line, 0, (size_t)(newline_pos - line));
	else
		clean_line = ft_substr(line, 0, ft_strlen(line));
	free(line);
	safe_alloc(clean_line);
	return (clean_line);
}

/**
 * @brief Recursively reads all lines from the map file
 * and allocates the map array.
 *
 * Reads each line of the map file,
 * storing them in a dynamically allocated array.
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
	if (!line && i == 0)
		return (NULL);
	if (i == 0)
		map()->size.x = ft_strlen(line);
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
	char	**map_cpy;

	fd = open(map_path, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		exit_so_long("Invalid file.\n");
	}
	map()->map = read_map(fd, 0);
	close(fd);
	safe_alloc(map()->map);
	validate_map();
	map_cpy = ft_tabcpy(map()->map);
	safe_alloc(map_cpy);
	flood_fill(map_cpy, player()->position);
	ft_tabfree(map_cpy);
	if (game()->map.filled == map()->pineapples + 1)
		return (true);
	else
		exit_so_long("Map is not valid, no valid path to exit or collectible!");
	return (true);
}
