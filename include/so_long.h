/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:06 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/03 20:42:01 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"

# ifdef __APPLE__
#  include "../lib/minilibx-opengl/mlx.h"
# else
#  include "../lib/minilibx-linux/mlx.h"
# endif

# include "handlers.h"
# include "graphics.h"
# include "parsing.h"
# include "utils.h"

/* Consider remove, but might use later! */
typedef struct s_entity
{
	t_point	position;
	bool	active;
}	t_entity;

/**
 * @brief Represents the player entity in the game.
 * Holds the player's position, number of moves made, and pineapples gathered.
 */
typedef struct s_player
{
	t_point	position;
	size_t	moves;
	size_t	pineapples;
}	t_player;

/**
 * @brief Represents the game map structure.
 * This structure is used to define positions and sizes in the game.
 */
typedef struct s_map
{
	char	**map;
	t_point	size;
	size_t	pineapples;
	size_t	filled;
}	t_map;

/**
 * @brief This structure holds the main game data, including the map,
 *  player state, and other entities.
 */
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
}	t_game;

t_player	*player(void);
t_map		*map(void);
t_game		*game(void);

#endif