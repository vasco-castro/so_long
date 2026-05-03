/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:57:16 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 22:13:21 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	safe_alloc(void *alloc)
{
	if (!alloc)
		exit_so_long("Allocation went wrong!!!");
}

void	free_game(void)
{
	if (game())
	{
		clean_textures();
		if (game()->win)
			mlx_destroy_window(game()->mlx, game()->win);
		if (game()->mlx)
		{
			mlx_destroy_display(game()->mlx);
			free(game()->mlx);
		}
		if (map()->map)
			ft_tabfree(map()->map);
	}
}
