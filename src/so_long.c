/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:28 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/10 20:44:24 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	so_long(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit(1);
	game()->win = mlx_new_window(game()->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		"You are going to have a fun ride ;)");
	if (!game()->win)
	{
		free(game()->win);
		exit(1);
	}

	render();

	// ft_put_image(WALL_TEXTURE, 0, 0);
	// ft_put_image(WALL_TEXTURE, 0, 1);
	// ft_put_image(WALL_TEXTURE, 1, 0);
	// ft_put_image(PLAYER_TEXTURE, 1, 1);
	// ft_put_image(COLLECTIBLE_TEXTURE, 2, 2);
	// ft_put_image(WALL_TEXTURE, 5, 5);
	// ft_put_image(EXIT_TEXTURE, 7, 5);

	// ft_put_sprite("./textures/dino/xpms/dino.xpm", 0, 0, 8);

	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game);
	mlx_loop(game()->mlx);
}

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
		if (parse_map(argv[1]))
		{
			ft_printf("Map is parsed correctly!\n");
			so_long();
		}
		else
		{
			ft_printf("\e[1;31mWhat a shit map bro!!\e[0m\n");
			exit(1);
		}
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
