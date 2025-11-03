/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:03:32 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/03 21:08:29 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* Render pineapples count aswell,
 and render a background to fix overlap.
 TODO: Add an offset to write the string, and every game setting */
static void	render_moves_count(void)
{
	char	*moves_str;
	char	*pineapples_str;
	char	*p_pineapples;
	char	*m_pineapples;
	char	*moves;

	moves = ft_itoa(player()->moves);
	moves_str = ft_strjoin(moves, " moves");
	mlx_string_put(game()->mlx, game()->win, 16, 16, 0x00CC0000,
		moves_str);
	free(moves);
	free(moves_str);
	p_pineapples = ft_itoa(player()->pineapples);
	m_pineapples = ft_itoa(map()->pineapples);
	pineapples_str = ft_strjoin("Collected ", p_pineapples);
	pineapples_str = ft_strjoin(pineapples_str, " / ");
	pineapples_str = ft_strjoin(pineapples_str, m_pineapples);
	pineapples_str = ft_strjoin(pineapples_str, " pineapples");
	mlx_string_put(game()->mlx, game()->win, 16, 32, 0x00CC0000,
		pineapples_str);
	free(pineapples_str);
	free(p_pineapples);
	free(m_pineapples);
}

static void	render_position(t_point p, char tile)
{
	if (tile == BACKGROUND || tile == PLAYER)
		ft_put_image(BACKGROUND_TEXTURE, p);
	else if (tile == WALL)
		ft_put_image(WALL_TEXTURE, p);
	else if (tile == COLLECTIBLE)
	{
		ft_put_image(BACKGROUND_TEXTURE, p);
		ft_put_image(COLLECTIBLE_TEXTURE, p);
	}
	else if (tile == EXIT)
		ft_put_image(EXIT_TEXTURE, p);
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
				ft_put_image(WALL_TEXTURE, pos);
			else
				render_position(pos, map()->map[y][x]);
			pos.x++;
		}
		pos.y++;
	}
	ft_put_image(PLAYER_TEXTURE, DEFAULT_PLAYER_POS);
	render_moves_count();
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
	// game()->win = mlx_new_window(game()->mlx, 500, 500, "Window 2");
	game()->win = mlx_new_window(game()->mlx, WIN_W, WIN_H,
		"You are going to have a fun ride ;)");
	if (!game()->win)
		exit_so_long(URED "MLX error!" RESET);
	mlx_hook(game()->win, 4, 0, mouse_handler, &game);
	mlx_hook(game()->win, 2, 1, key_handler, &game);
	mlx_hook(game()->win, 17, 1, close_window, &game);
	render();
	mlx_loop(game()->mlx);
}
