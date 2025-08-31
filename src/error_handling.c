/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:50 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 15:57:03 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(void)
{
	if (game())
	{
		if (game()->mlx)
			free(game()->mlx);
		if (game()->win)
			free(game()->win);
		if (map()->map)
			ft_tabdel(map()->map, map()->size.y -1);
	}
}

void	exit_so_long(char *error)
{
	ft_fprintf(2, RED "Error\n%s\n" RESET, error);
	free_game();
	exit(EXIT_FAILURE);
}

void	exit_successfully(char *sucess)
{
	ft_printf(BIGREEN "%s\n" RESET, sucess);
	free_game();
	exit(EXIT_SUCCESS);
}
