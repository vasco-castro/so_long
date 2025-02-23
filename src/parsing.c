/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/23 18:35:11 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	fill(char *map[], t_position size, int row, int col)
{
	ft_printf("MAX POSITION: %d - %d\n\n", size.x, size.y);
	ft_printf("\nCURRENT POSITION: %d - %d\n", row, col);
	ft_printf("CURRENT VALUE: %c\n", map[row][col]);
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return (0);

	ft_printf("TEST 1, CURRENT VALUE: %c\n", map[row][col]);

	if (map[row][col] == EXIT)
		return (1);

	ft_printf("TEST 2, CURRENT VALUE: %c\n", map[row][col]);

	map[row][col] = 'F';

	ft_printf("TEST 3, CURRENT VALUE: %c\n", map[row][col]);

	if (map[row - 1][col] != WALL | map[row - 1][col] != 'F')
		if (fill(map, size, row - 1, col))
			return (1);

	ft_printf("TEST 4\n");
	if (map[row + 1][col] != WALL | map[row + 1][col] != 'F')
		if (fill(map, size, row + 1, col))
			return (1);

	ft_printf("TEST 5\n");
	if (map[row][col - 1] != WALL | map[row][col - 1] != 'F')
		if (fill(map, size, row, col - 1))
			return (1);

	ft_printf("TEST 6\n");
	if (map[row][col + 1] != WALL | map[row][col + 1] != 'F')
		if (fill(map, size, row, col + 1))
			return (1);

	ft_printf("TEST 7\n");
	return (0);
}

bool	flood_fill(char *map[], t_position size, t_position start)
{
	char	**tmp_map;

	tmp_map = map;
	return (fill(tmp_map, size, start.x, start.y));
}

/* TODO: this function will:
 count collectibles, player, exit, and map size (both line lenght and height)
 insert all thoes values into the struct
 and give an error in case of it;
 */
void	check_line(char *new_line)
{
	(void) new_line;
}

bool	parse_map(char *map_path)
{
	int		fd;
	int		line_len;
	char	*line;

	game()->map.size.y = 0;
	line = 0;
	game()->map.map = malloc(sizeof(char **));
	fd = open(map_path, O_RDONLY);
	if (fd < 1)
		exit(1); // TODO: launch MAP-ERROR;
	while (line)
	{
		line = get_next_line(fd);
		check_line(line);
		line_len = ft_strlen(line);
		game()->map.size.x = line_len;
		if (game()->map.size.y < 1)
			if (line_len != game()->map.size.x) // if (line_len != ft_strlen(map[size.y-1]))
				exit (1);
		if (line_len < 3)
			exit(1); // TODO: FREE THE OTHER ALLOCATED LINES and the map array; & launch MAP-ERROR;
		game()->map.map[game()->map.size.y] = malloc(line_len + 1);
		if (!game()->map.map[game()->map.size.y])
			exit(1);
		game()->map.map[game()->map.size.y] = line;// TODO: alloc memory for each line, and copy them to the map array;
		game()->map.size.y++;
		free(line);
	}
	close(fd);
		//TODO: GET PLAYER POSITION
	ft_printtab(game()->map.map);
	return (flood_fill(game()->map.map, game()->map.size, game()->map.player.position));
}

/* int main(int argc, char *argv[])
{
	char **map;
	// TODO: alloc memory for map array
	map = malloc(sizeof(char **) + 1);
	map = parse_map(argv[1]);

	ft_printtab(map);
	return (0);
} */