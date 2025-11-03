/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/03 21:06:22 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"

# define WIN_SQUARE
// # define WIN_480P
// # define WIN_720P
// # define WIN_1080P

# ifdef WIN_SQUARE
#  define WIN_W 576
#  define WIN_H 576
# elif defined(WIN_480P)
#  define WIN_W 640
#  define WIN_H 480
# elif defined(WIN_720P)
#  define WIN_W 1280
#  define WIN_H 720
# elif defined(WIN_1080P)
#  define WIN_W 1920
#  define WIN_H 1080
# endif

# define F_TEXTURE "./assets/textures/hugo/collectible.xpm"
# define PLAYER_TEXTURE "./assets/textures/dino/dino.xpm"
# define BACKGROUND_TEXTURE "./assets/textures/dino/background.xpm"

# define WALL_TEXTURE "./assets/textures/hugo/wall.xpm"
# define EXIT_TEXTURE "./assets/textures/hugo/exit.xpm"
# define COLLECTIBLE_TEXTURE "./assets/textures/pineapple.xpm"

# define TEXTURE_SIZE 64

# define MAX_GRID_W (WIN_W / TEXTURE_SIZE) // 576 / 64 = 9
# define MAX_GRID_H (WIN_H / TEXTURE_SIZE) // 324 / 64 = 5
# define MAX_GRID_POS (t_point){MAX_GRID_W - 1, MAX_GRID_H - 1} // (8, 4)
# define MIN_GRID_POS (t_point){0, 0} // (0, 0)
# define DEFAULT_PLAYER_POS (t_point){MAX_GRID_W / 2, MAX_GRID_H / 2} // (4, 2)

typedef struct s_image
{
	void	*image;
	char	*address;
	int		width;
	int		height;
	int		bpp; // bits per pixel
	int		size_line;
	int		endian;
}		t_image;

void	game_init(void);
void	render(void);

void	ft_put_image(char *texture, t_point p);
void	ft_put_sprite(char *texture, t_point p, int frame_index);

#endif