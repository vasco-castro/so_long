/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:50 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/04 20:15:38 by vsoares-         ###   ########.fr       */
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
	ft_printf_fd(RED "Error\n%s\n" RESET, 2, error);
	free_game();
	exit(EXIT_FAILURE);
}

void	exit_successfully(void)
{
	ft_printf(BIGREEN "Congratulations, you finish the game :)\n" RESET);
	free_game();
	exit(EXIT_SUCCESS);
}
