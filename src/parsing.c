/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:40 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/17 17:20:49 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO: this function will:
 count collectibles, player, exit, and map size (both line lenght and height)
 insert all thoes values into the struct
 and give an error in case of it;
 */
static bool	check_line(char *line)
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

static char	*get_map_line(int fd)
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
	/*TODO: find how many lines to alloc the right ammount */
	game()->map.map = malloc(sizeof(char **) * 6);
	fd = open(map_path, O_RDONLY);
	if (fd < 1)
		exit(1); // TODO: launch MAP-ERROR;
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
			ft_printf("BRUH!\n"); //TODO: Handle this! And save last line, if not the map does not have a NULL at the end!!
		if (game()->map.size.x < 3)
			exit(1); // TODO: FREE THE OTHER ALLOCATED LINES and the map array; & launch MAP-ERROR;
	}
	close(fd);
	return (flood_fill());
}
