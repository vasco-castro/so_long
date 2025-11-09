/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/09 17:47:43 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* Render pineapples count aswell,
 and render a background to fix overlap.
 TODO: Add an offset to write the string, and every game setting */
static void	render_move_count(void)
{
	char	*moves_str;
	char	*moves;

	moves = ft_itoa(player()->moves);
	moves_str = ft_strjoin(moves, " moves");
	mlx_string_put(game()->mlx, game()->win, 16, 16, 0x00CC0000,
		moves_str);
	free(moves);
	free(moves_str);
}

static void	render_pineapple_count(void)
{
	char	*pineapples_str;
	char	*pineapples;
	char	*temp;

	pineapples = ft_itoa(player()->pineapples);
	temp = ft_strjoin("Collected ", pineapples);
	free(pineapples);
	pineapples_str = temp;
	temp = ft_strjoin(pineapples_str, " / ");
	free(pineapples_str);
	pineapples_str = temp;
	pineapples = ft_itoa(map()->pineapples);
	temp = ft_strjoin(pineapples_str, pineapples);
	free(pineapples);
	free(pineapples_str);
	pineapples_str = temp;
	temp = ft_strjoin(pineapples_str, " pineapples");
	mlx_string_put(game()->mlx, game()->win, 16, 32, 0x00CC0000,
		pineapples_str);
	free(pineapples_str);
	free(temp);
}

static void	render_position(t_point p, char tile)
{
	if (tile == BACKGROUND || tile == PLAYER)
		put_scaled(&game()->textures.sand, p);
	else if (tile == WALL)
		put_scaled(&game()->textures.water, p);
	else if (tile == COLLECTIBLE)
	{
		put_scaled(&game()->textures.sand, p);
		put_scaled(&game()->textures.pineapple, p);
	}
	else if (tile == EXIT)
		put_scaled(&game()->textures.exit, p);
}

/* Extra TODO: Implement player sprite animation. Using image frame_index */
void	render(void)
{
	int		x;
	int		y;
	t_point	pos;

	pos = MIN_GRID_POS;
	while (pos.y <= MAX_GRID_POS.y)
	{
		pos.x = 0;
		while (pos.x <= MAX_GRID_POS.x)
		{
			x = player()->position.x - (MAX_GRID_W / 2) + pos.x;
			y = player()->position.y - (MAX_GRID_H / 2) + pos.y;
			if (x < 0 || y < 0 || x >= (int)map()->size.x
				|| y >= (int)map()->size.y)
				put_scaled(&game()->textures.water, pos);
			else
				render_position(pos, map()->map[y][x]);
			pos.x++;
		}
		pos.y++;
	}
	put_scaled(&game()->textures.player, DEFAULT_PLAYER_POS);
	render_move_count();
	render_pineapple_count();
	ft_printf(BIBLUE "%t\n" RESET, map()->map);
}

/**
 * @brief Initializes the game window and starts the main event loop.
 * Sets up MLX, creates the window, renders the initial state,
 * and hooks event handlers.
 */
void	game_init(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_so_long(URED "MLX error!" RESET);
	game()->win = mlx_new_window(game()->mlx, WIN_W, WIN_H,
		"You are going to have a fun ride ;)");
	if (!game()->win)
		exit_so_long(URED "MLX error!" RESET);
	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game);
	load_textures();
	render();
	mlx_loop(game()->mlx);
}
