/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:06 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:46:43 by vsoares-         ###   ########.fr       */
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

typedef struct s_player
{
	t_point	position;
	int			moves;
	int			collectibles;
}	t_player;

typedef struct s_entity
{
	t_point	position;
	bool		active;
}	t_entity;

typedef struct s_map
{
	char		**map;
	t_point	size;

	t_player	player;
	t_entity	exit;
	// t_entity		*enemies;
	// t_entity	*collectibles;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

t_game	*game(void);

void	free_game(void);
void	exit_so_long(char *error);
void	exit_successfully(void);

#endif