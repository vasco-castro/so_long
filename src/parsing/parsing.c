/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/04 20:24:20 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* Checks if the map is valid and saves position and counters of map metadata.
TODO: Still need to validate all walls (considering to do it in floodfill yet!)
*/
static void parse_map(void)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game()->map.map[y])
	{
		if (game()->map.size.x != ft_strlen(game()->map.map[y]))
			exit_so_long("Map size is incompatibly!");
		x = 0;
		while (game()->map.map[y][x])
		{
			if (game()->map.map[y][x] == PLAYER)
				game()->map.player.position = (t_point) {x, y};
			if (game()->map.map[y][x] == EXIT)
				game()->map.exit.position = (t_point) {x, y};
			if (game()->map.map[y][x] == COLLECTIBLE)
				game()->map.collectibles++;
			x++;
		}
		y++;
	}
}

/* Replace some code with ft_substr */
static char	*get_map_line(int fd)
{
	int		i;
	char	*line;
	char	*clean_line;

	i = 0;
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		return (NULL);
	clean_line = malloc(ft_strlen(line) + 1);
	if (!clean_line)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		clean_line[i] = line[i];
		i++;
	}
	clean_line[i] = 0;
	free(line);
	return (clean_line);
}

/* Read and allocate map recursivly */
static char **read_map(int fd, size_t i)
{
	char	*line;
	char	**result;

	line = get_map_line(fd);
	if (i == 0)
		game()->map.size.x = ft_strlen(line);
	if (!line && i == 0)
		return (NULL);
	else if (!line && i != 0)
	{
		game()->map.size.y = i;
		return (ft_calloc(sizeof(char *), (i + 1)));
	}
	result = read_map(fd, i + 1);
	result[i] = line;
	return (result);
}

/* Read the map file and save it in the map struct */
bool	get_map(char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		exit_so_long("Invalid file.\n");
	}
	game()->map.map = read_map(fd, game()->map.size.y);
	close(fd);
	if (!game()->map.map)
		exit_so_long("Allocation went wrong!\n");
	ft_printf(BGREEN "Allocated map of size %d-%d successfully!\n"RESET"%t\n",
		game()->map.size.x, game()->map.size.y, game()->map.map);
	parse_map();
	return (true);
}
