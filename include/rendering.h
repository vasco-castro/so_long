/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/30 22:12:34 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

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

void	render(void);

void	ft_put_image(char *texture, t_point p);
void	ft_put_sprite(char *texture, t_point p, int frame_index);

#endif