/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:57:16 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/06 20:41:36 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_game(void)
{
	if (game())
	{
		if (game()->win)
			mlx_destroy_window(game()->mlx, game()->win);
		if (game()->mlx)
		{
			mlx_destroy_display(game()->mlx);
			free(game()->mlx);
		}
		if (map()->map)
			ft_tabdel(map()->map, map()->size.y - 1);
	}
}
