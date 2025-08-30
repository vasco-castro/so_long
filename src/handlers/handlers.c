/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 12:04:34 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Closes the game window and frees resources.
 * @return EXIT_SUCCESS on successful exit.
 */
int	close_window(void)
{
	exit_successfully("Exiting the game. Goodbye!\n");
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles keyboard input events.
 * @param keycode The code of the key pressed.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_handler(int keycode)
{
	if (keycode == ESCAPE_KEY || keycode == CLOSE_KEY)
		exit_successfully("Exiting the game. Goodbye!\n");
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_up();
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		move_left();
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_down();
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_right();
	else
		ft_printf("Pressed key: \033[31m%d\033[0m\n", keycode);
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles mouse input events.
 * @param mousecode The code of the mouse event.
 * @param x The x-coordinate of the mouse event in the window.
 * @param y The y-coordinate of the mouse event in the window.
 * @return EXIT_SUCCESS after handling the mouse event.
 */
int	mouse_handler(int mousecode, int x, int y)
{
	if (mousecode == 1)
		ft_printf("Left Click in %d-%d\n", x, y);
	else if (mousecode == 2)
		ft_printf("Right Click in %d-%d\n", x, y);
	else if (mousecode == 3)
		ft_printf("Middle Click in %d-%d\n", x, y);
	else if (mousecode == 4)
		ft_printf("Scroll UP in %d-%d\n", x, y);
	else if (mousecode == 5)
		ft_printf("Scroll DOWN in %d-%d\n", x, y);
	else if (mousecode == 6)
		ft_printf("Scroll right in %d-%d\n", x, y);
	else if (mousecode == 7)
		ft_printf("Scroll left in %d-%d\n", x, y);
	else
		ft_printf("Unkown mouse action with code: %d, in %d-%d\n",
			mousecode, x, y);
	return (EXIT_SUCCESS);
}
