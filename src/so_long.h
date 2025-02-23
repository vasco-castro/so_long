/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:06 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/23 19:19:45 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/minilibx-linux/mlx.h"
# include "../includes/libft/libft.h"
# include "handlers.h"

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280

# define PLAYER 'P'
# define WALL '1'
# define BACKGROUND '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_player
{
	t_position	position;
	int			moves;
	int			collectables;
}	t_player;

typedef struct s_enemy
{
	t_position	position;
	bool		alive; //TODO: make a way to kill enemies
}	t_enemy;

typedef struct s_collectable
{
	t_position	position;
	bool		active;
}	t_collectable;

typedef struct s_map
{
	char		**map;
	t_position	size;

	t_player	player;
	t_enemy		*enemies;
	t_position	*collectables;
	t_position	exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game; //TODO: Might call it just t_mlx and not need img pointer

bool	fill(char *map[], t_position size, int row, int col);
bool	flood_fill(char *map[], t_position size, t_position start);

bool	parse_map(char *map_path);

t_game	*game(void);

#endif