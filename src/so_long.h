/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:06 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/20 16:28:14 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../inc/minilibx-linux/mlx.h"
# include "../inc/libft/inc/libft.h"
# include "handlers/handlers.h"
# include "rendering/rendering.h"
# include "parsing/parsing.h"

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280

typedef struct s_image
{
	void	*image;
	char	*address;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}		t_image;

typedef struct s_player
{
	t_position	position;
	int			moves;
	int			collectibles;
}	t_player;

typedef struct s_enemy
{
	t_position	position;
	bool		alive; //TODO: make a way to kill enemies
}	t_enemy;

typedef struct s_collectible
{
	t_position	position;
	bool		active;
}	t_collectible;

typedef struct s_map
{
	char		**map;
	t_position	size;

	t_player	player;
	t_enemy		*enemies;
	t_position	*collectibles;
	t_position	exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

t_game	*game(void);

#endif