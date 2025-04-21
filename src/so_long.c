/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:28 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 21:01:35 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_valid_file(const char *filename, const char *file_extension) {
    const char *dot = ft_strrchr(filename, file_extension[0]);
    if (!dot || dot == filename) return false; // No dot or dot is first character
    return ft_strcmp(dot, file_extension) == 0;
}

static void	so_long(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_so_long(URED "MLX error!" RESET);
	game()->win = mlx_new_window(game()->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		"You are going to have a fun ride ;)");
	if (!game()->win)
		exit_so_long(URED "MLX error!" RESET);
	render();
	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game);
	mlx_loop(game()->mlx);
}

// TODO: DO DEBUG CHECKER ;)
int	main(int argc, char *argv[])
{
	if (argc == 1)
		exit_so_long(RED "You didn't pass the map as an argument." RESET);
	else if (argc == 2)
	{
		if (!is_valid_file(argv[1], ".ber"))
			exit_so_long("Invalid file.\n");
		if (!parse_map(argv[1]))
		{
			ft_printf(UGREEN "%sMap is parsed correctly!\n" RESET);
			so_long();
		}
		else
			exit_so_long(RED "What a shit map bro!!\n" RESET);
	}
	else
		exit_so_long(RED "Exit\nToo many arguments.\n" RESET);
	return (EXIT_SUCCESS);
}

t_game	*game(void)
{
	static t_game	data;

	return (&data);
}
