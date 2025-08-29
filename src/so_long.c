/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:28 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 19:22:38 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	so_long(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_so_long(URED "MLX error!" RESET);
	game()->win = mlx_new_window(game()->mlx, WIN_W, WIN_H,
		"You are going to have a fun ride ;)");
	if (!game()->win)
		exit_so_long(URED "MLX error!" RESET);
	render();
	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game); //TODO: Remove, might be activated by key handler 17!!!
	mlx_loop(game()->mlx);
}

// TODO: DO DEBUG CHECKER ;)
int	main(int argc, char *argv[])
{
	if (argc == 1)
		exit_so_long(RED "You didn't pass the map as an argument." RESET);
	else if (argc == 2)
	{
		if (!ft_isfile(argv[1], ".ber"))
			exit_so_long("Invalid file.\n");
		if (get_map(argv[1]))
		{
			ft_printf(UGREEN "Map is parsed correctly!\n" RESET);
			ft_printf(BIGREEN "%t" RESET, game()->map.map);
			so_long();
		}
		else
			exit_so_long(RED "What a shit map bro!!\n" RESET);
	}
	else
		exit_so_long(RED "Exit\nToo many arguments.\n" RESET);
	return (EXIT_SUCCESS);
}

/**
 * @brief Singleton with all main game structure information!
 */
t_game	*game(void)
{
	static t_game	data;

	return (&data);
}
