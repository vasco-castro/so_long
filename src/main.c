/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:28 by vsoares-          #+#    #+#             */
/*   Updated: 2025/09/07 12:26:39 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Singleton accessor for the main game structure.
 * Returns a pointer to the unique game instance containing all game state.
 *
 * @return Pointer to the main game structure (t_game).
 */
t_game	*game(void)
{
	static t_game	data;

	return (&data);
}

/**
 * @brief Singleton accessor for the map structure.
 * Returns a pointer to the unique map instance within the game.
 *
 * @return Pointer to the map structure (t_map).
 */
t_map	*map(void)
{
	return (&game()->map);
}

/**
 * @brief Singleton accessor for the player structure.
 * Returns a pointer to the unique player instance within the game.
 *
 * @return Pointer to the player structure (t_player).
 */
t_player	*player(void)
{
	return (&game()->player);
}

/**
 * @brief Entry point for the so_long game.
 * Checks arguments, validates the map file, parses the map,
 * and starts the game loop.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Exit status code.
 * TODO: Make DEBUG mode!
 */
int	main(int argc, char *argv[])
{
	if (argc == 1)
		exit_so_long(RED "You didn't pass the map as an argument." RESET);
	else if (argc == 2)
	{
		if (!ft_isfile(argv[1], ".ber"))
			exit_so_long("Invalid file.\n");
		if (!get_map(argv[1]))
			exit_so_long(RED "What a shit map bro!!\n" RESET);
		ft_printf(BGREEN "Map is parsed correctly!\n" RESET "%t\n", map()->map);
		game_init();
	}
	else
		exit_so_long(RED "Exit\nToo many arguments.\n" RESET);
	return (EXIT_SUCCESS);
}
