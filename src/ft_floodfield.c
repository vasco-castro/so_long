/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfield.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:51:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/17 17:22:14 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_positioncheckedorinvalid(char *map[], t_position p)
{
	// ft_printf("CHECKING POSITION: %d.%d -> %c\n", p.x, p.y, map[p.y][p.x]);
	return (p.x < 0 || p.y < 0
		|| p.x >= game()->map.size.x || p.y >= game()->map.size.y
		|| map[p.y][p.x] == WALL || map[p.y][p.x] == 'F'
	);
}

static bool	fill(char *map[], t_position p)
{
	t_position	temp_p;

	/* Check if it's surrounded by walls before flood_field */
	/* TODO: Floodfill until the amount of Collectibles is flooded and exit too */
	if (map[p.y][p.x] == EXIT)
		return (1);
	map[p.y][p.x] = 'F';
	temp_p.x = p.x;
	temp_p.y = p.y - 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
		if (fill(map, temp_p))
			return (1);
	temp_p.y = p.y + 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
		if (fill(map, temp_p))
			return (1);
	temp_p.y = p.y;
	temp_p.x = p.x - 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
		if (fill(map, temp_p))
			return (1);
	temp_p.x = p.x + 1;
	if (!ft_positioncheckedorinvalid(map, temp_p))
		if (fill(map, temp_p))
			return (1);
	return (0);
}

bool	flood_fill(void)
{
	char	**tmp_map;

	tmp_map = game()->map.map;
	bool bol = fill(tmp_map, game()->map.player.position);
	ft_printtab(tmp_map);
	return (bol);
}
