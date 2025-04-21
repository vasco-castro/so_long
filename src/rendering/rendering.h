/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/21 22:54:27 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# define PLAYER_TEXTURE "./textures/dino/dino.xpm"
# define BACKGROUND_TEXTURE "./textures/dino/background.xpm"

# define WALL_TEXTURE "./textures/hugo/wall.xpm"
# define EXIT_TEXTURE "./textures/hugo/exit.xpm"
# define COLLECTIBLE_TEXTURE "./textures/hugo/collectible.xpm"

# define TEXTURE_SIZE 64

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

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

void	draw_background(t_position position);
void	draw_collects(t_position position);
void	draw_player(t_position position);
void	draw_walls(t_position position);
void	draw_exit(t_position position);

void	render(void);

void	ft_put_image(char *texture, int x, int y);
void	ft_put_upscale_image(char *texture, int x, int y);
void	ft_put_sprite(char *texture, int x, int y, int frame_index);

#endif