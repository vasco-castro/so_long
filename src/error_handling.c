/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:50 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 22:45:59 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(void)
{
	if (game())
	{
		if (game()->mlx)
			free(game()->mlx);
		if (game()->win)
			free(game()->win);
		if (game()->map.map)
			ft_tabdel(game()->map.map, game()->map.size.y -1);
	}
}

void	exit_so_long(char *error)
{
	ft_printf_fd("Exit\n", 2);
	ft_printf_fd("%s\n", 2, error);
	free_game();
	exit(1);
}
