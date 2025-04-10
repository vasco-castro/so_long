/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/06 19:13:35 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

int	close_window(void)
{
	ft_printf("It was good to have you, bye ;)\n");
	if (game()->win != NULL)
		mlx_destroy_window(game()->mlx, game()->win);
	if (game()->mlx != NULL)
	{
		mlx_destroy_display(game()->mlx);
		free(game()->mlx);
	}
	exit(0);
	return (0);
}

//TODO: CHANGE PROTOTYPE OF ENV/GAME TO MLX OR SOMETHING
int	key_handler(int keycode)
{
	if (keycode == ESC || keycode == CLOSE)
		close_window();
	else if (keycode == W || keycode == UP)
		ft_printf("UP\n");
	else if (keycode == A || keycode == LEFT)
		ft_printf("LEFT\n");
	else if (keycode == S || keycode == DOWN)
		ft_printf("DOWN\n");
	else if (keycode == D || keycode == RIGHT)
		ft_printf("RIGHT\n");
	else
		ft_printf("KEY: \033[31m%d\033[0m\n", keycode);
	return (EXIT_SUCCESS);
}

/** x and y parameters are the pixel coordinates of the mouse
* in the window when the event was emitted
* you can use them to check that the user clicked in a specific region
* of the window
*/
int	mouse_handler(int mousecode, int x, int y)
{
	if (mousecode == 1)
		ft_printf("Left Click in %d-%d", x, y);
	else if (mousecode == 2)
		ft_printf("Right Click in %d-%d", x, y);
	else if (mousecode == 3)
		ft_printf("Middle Click in %d-%d", x, y);
	else if (mousecode == 4)
		ft_printf("Scroll UP in %d-%d", x, y);
	else if (mousecode == 5)
		ft_printf("Scroll DOWN in %d-%d", x, y);
	else if (mousecode == 6)
		ft_printf("Scroll right in %d-%d", x, y);
	else if (mousecode == 7)
		ft_printf("Scroll left in %d-%d", x, y);
	else
		ft_printf("%d\n", mousecode);
	return (EXIT_SUCCESS);
}
