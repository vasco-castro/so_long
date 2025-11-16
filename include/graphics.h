/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/16 18:21:51 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"

// # define WIN_SQUARE
// # define WIN_480P
# define WIN_720P
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

# define PLAYER_TEXTURE "./assets/textures/dino/dino.xpm"
# define PLAYER_SPRITE_SIZE 24

# define COLLECTIBLE_TEXTURE "./assets/textures/pineapple.xpm"

# define WALL_TEXTURE "./assets/textures/tiles/Water.xpm"
// # define EXIT_TEXTURE "./assets/textures/sand/x_mark.xpm"
# define EXIT_TEXTURE "./assets/textures/dino/cross.xpm"
// # define BACKGROUND_TEXTURE "./assets/textures/sand/sand.xpm"
# define BACKGROUND_TEXTURE "./assets/textures/dino/background.xpm"

# define F_TEXTURE "./assets/textures/dino/background.xpm"

# define TEXTURE_SIZE 64

typedef struct s_image
{
	void	*img;
	char	*addr; // address
	int		w; // width
	int		h; // height
	int		bpp; // bits per pixel
	int		line; //line lenght (size)
	int		endian;
}		t_image;

typedef struct s_textures
{
	t_image	player;
	t_point	player_pos;
	t_image	pineapple;
	t_image	water;
	t_image	sand;
	t_image	exit;
}	t_textures;

void	game_init(void);
void	render(void);

t_image	scale_xpm(char *path);
t_image	scale_sprite(char *path, int sx, int sy);
void	put_scaled(t_image *img, t_point p);

void	load_textures(void);
void	clean_textures(void);

#endif