/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:57:16 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/03 21:08:02 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_game(void)
{
	if (game())
	{
		if (game()->mlx)
			free(game()->mlx);
		if (game()->win)
			free(game()->win);
		if (map()->map)
			ft_tabdel(map()->map, map()->size.y - 1);
	}
}
