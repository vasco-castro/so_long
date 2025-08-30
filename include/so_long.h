/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:06 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 19:15:18 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
#  include "../lib/minilibx-opengl/mlx.h"
# else
#  include "../lib/minilibx-linux/mlx.h"
# endif

# include "../lib/libft/include/libft.h"

# include "handlers.h"
# include "rendering.h"
# include "parsing.h"

// # define WIN_360P
# define WIN_720P
// # define WIN_1080P

# ifdef WIN_360P
#  define WIN_W 640
#  define WIN_H 360
# endif

# ifdef WIN_720P
#  define WIN_W 1280
#  define WIN_H 720
# endif

# ifdef WIN_1080P
#  define WIN_W 1920
#  define WIN_H 1080
# endif

typedef struct s_player
{
	t_point	position;
	size_t	moves;
	size_t	collectibles;
}	t_player;

/* Consider remove, but might use later! */
typedef struct s_entity
{
	t_point	position;
	bool	active;
}	t_entity;

/**
 * @brief Represents the game map structure.
 * This structure is used to define positions and sizes in the game.
 * TODO: Move player to t_game, and remove exit entirely since is not
 *  overwriten in the map anymore.
 */
typedef struct s_map
{
	char		**map;
	t_point		size;

	t_player	player;
	t_entity	exit;
	size_t		collectibles;
}	t_map;

/**
 * @brief This structure holds the main game data, including the map,
 *  player state, and other entities.
 * TODO: Change this to t_solong and change t_map to t_game.
 */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

t_game	*game(void);

void	free_game(void);
void	exit_so_long(char *error);
void	exit_successfully(char *sucess);

#endif