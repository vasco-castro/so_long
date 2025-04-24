/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 19:25:34 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* TODO: this function will:
 count collectibles, player, exit, and map size (x & y)
 insert all thoes values into the struct
 and give an error in case of it;
 */
static bool	check_line(char *line)
{
	size_t	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == PLAYER)
		{
			game()->map.player.position.y = game()->map.size.y;
			game()->map.player.position.x = x;
		}
		if (line[x] == EXIT)
		{
			game()->map.exit.position.y = game()->map.size.y;
			game()->map.exit.position.x = x;
		}
		x++;
	}
	if (game()->map.size.y == 0)
		game()->map.size.x = x;
	else if (((game()->map.size.y != 0) && (game()->map.size.x != x)) || x < 3)
		exit(EXIT_FAILURE);
	game()->map.map[game()->map.size.y] = line;
	return (EXIT_SUCCESS);
}

void	parse_check(void)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game()->map.map[y])
	{
		ft_printf("%d - %d", game()->map.size.x, ft_strlen(game()->map.map[y]));
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

char	**read_map(int fd, size_t i)
{
	char	*line;
	char	**result;

	line = get_map_line(fd);
	if (i ==0)
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
	ft_printf("MAP RECURSIVLY of size %d-%d:\n%t\n",
		game()->map.size.x, game()->map.size.y, game()->map.map);

	parse_check();
	return (true);
}

/* TODO: Still need to properly allocate the map
	Suggestion to do it recursevily;
	And need to separate this into more functions */
bool	parse_map(char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 1)
		exit_so_long("Invalid file.\n");
	game()->map.size.y = 0;
	game()->map.map = malloc(200 * sizeof(char *));
	if (!game()->map.map)
		exit_so_long("Allocation went wrong!\n");
	while (game()->map.size.y == 0 || line)
	{
		line = get_map_line(fd);
		if (line)
		{
			if (check_line(line))
				exit(1);
			else
				game()->map.size.y++;
		}
		else
			ft_printf("BRUH!\n");
		//TODO: Handle this! And save last line, if not the map does not have a NULL at the end!!
		if (game()->map.size.x < 3)
			exit_so_long("Map is too small!\n");
	}
	close(fd);
	return (flood_fill(game()->map.map, game()->map.player.position));
}
