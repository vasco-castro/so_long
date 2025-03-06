/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:28 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:16 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	so_long(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit(1);
	game()->win = mlx_new_window(
		game()->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!"
		);
	if (!game()->win)
	{
		free(game()->win);
		exit(1);
	}
	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game);
	mlx_loop(game()->mlx);
}

// void	map_init(char *map)
// {
// 	ft_printf("%d", DEBUG_MODE);
// 	debug("MAP -> %s", map);
// }

// TODO: DO DEBUG CHECKER ;)
int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_printf("You didn't pass the map as an argument.");
		exit(1);
	}
	else if (argc == 2)
	{
		parse_map(argv[1]);
		so_long();
	}
	else
	{
		ft_printf("Exit\nToo many arguments.\n");
		exit(1);
	}
	return (0);
}

t_game	*game(void)
{
	static t_game	data;

	return (&data);
}
