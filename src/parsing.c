/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/06 22:20:52 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_positioncheckedorinvalid(char *map[], t_position p)
{
	ft_printf("CHECKING POSITION: %d.%d -> %c\n", p.x, p.y, map[p.y][p.x]);
	return (p.x < 0 || p.y < 0 ||
		p.x >= game()->map.size.x || p.y >= game()->map.size.y ||
		map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

/**
 * TODO: Correct FLOOD_FILL
*/
bool	fill(char *map[], t_position size, t_position p)
{
	t_position temp_p;
	// static int test = 0;
	// test++;
	// ft_printf("TEST: %d\tCURRENT POSITION: %d.%d\n", test, p.x, p.y);
	// if (test == 5)
	// 	return (0);

	if (p.x < 0 || p.y < 0 || p.x >= size.x || p.y >= size.y)
		return (0);

	if (map[p.y][p.x] == EXIT)
		return (1);

	ft_printf("DEBUG | CURRENT VALUE IS: %c\n", map[p.y][p.x]);

	map[p.y][p.x] = 'F';

	ft_printf("DEBUG | CHANGED VALUE TO: %c\n\n", map[p.y][p.x]);
	ft_printtab(map);
	ft_printchar('\n');

	temp_p.x = p.x;
	temp_p.y = p.y - 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
	{
		if (fill(map, size, temp_p))
			return (1);
	}
	temp_p.y = p.y + 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
	{
		if (fill(map, size, temp_p))
			return (1);
	}
	temp_p.y = p.y;
	temp_p.x = p.x - 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
	{
		if (fill(map, size, temp_p))
			return (1);
	}
	temp_p.x = p.x + 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
	{
		if (fill(map, size, temp_p))
			return (1);
	}

	return (0);
}

bool	flood_fill(char *map[], t_position size, t_position start)
{
	char	**tmp_map;
	bool	bol;
	// bol = 0;

	tmp_map = map;
	ft_printf("| MAX		POSITION: %d - %d |\n", size.x, size.y);
	ft_printf("| PLAYER		POSITION: %d - %d |\n\n", start.x, start.y);
	ft_printf("| EXIT		POSITION: %d - %d |\n\n", game()->map.exit.x, game()->map.exit.y);

	bol = fill(tmp_map, size, start);

	ft_printtab(tmp_map);
	return (bol);
}

/* TODO: this function will:
 count collectibles, player, exit, and map size (both line lenght and height)
 insert all thoes values into the struct
 and give an error in case of it;
 */
bool	check_line(char *line)
{
	int	x;

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
			game()->map.exit.y = game()->map.size.y;
			game()->map.exit.x = x;
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

char	*get_map_line(int fd)
{
	int		i;
	char	*line;
	char	*clean_line;

	i = 0;
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		return (NULL);
	clean_line = malloc(ft_strlen(line));
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

bool	parse_map(char *map_path)
{
	int		fd;
	char	*line;

	game()->map.size.y = 0;
	line = 0;

	game()->map.map = malloc(sizeof(char **) * 6);
	fd = open(map_path, O_RDONLY);
	if (fd < 1)
		exit(1); // TODO: launch MAP-ERROR;
	while (line || game()->map.size.y == 0)
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
			ft_printf("BRUH!\n"); //TODO: Handle this! And save last line, if not the map does not have a NULL at the end!!

		if (game()->map.size.x < 3)
			exit(1); // TODO: FREE THE OTHER ALLOCATED LINES and the map array; & launch MAP-ERROR;

	}
	close(fd);

	ft_printf("DEBUG - FINISHED PARSING MAP:\n");
	ft_printtab(game()->map.map);
	ft_printf("\n");

	return (flood_fill(game()->map.map, game()->map.size, game()->map.player.position));
}
