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

# include "../inc/minilibx-linux/mlx.h"
# include "../inc/libft/inc/libft.h"
# include "handlers/handlers.h"
# include "rendering/rendering.h"
# include "parsing/parsing.h"

// # define WIN_360P
# define WIN_720P
//# define WIN_1080P

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

typedef struct s_entity
{
	t_point	position;
	bool	active;
}	t_entity;

typedef struct s_map
{
	char		*path;
	char		**map;
	t_point		size;

	t_player	player;
	t_entity	exit;
	size_t		collectibles;
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