/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:41:02 by vsoares-          #+#    #+#             */
/*   Updated: 2025/08/04 19:43:31 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# define F_TEXTURE "./textures/hugo/collectible.xpm"
# define PLAYER_TEXTURE "./textures/dino/dino.xpm"
# define BACKGROUND_TEXTURE "./textures/dino/background.xpm"

# define WALL_TEXTURE "./textures/hugo/wall.xpm"
# define EXIT_TEXTURE "./textures/hugo/exit.xpm"
# define COLLECTIBLE_TEXTURE "./textures/pineapple.xpm"

# define TEXTURE_SIZE 64

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

void	render(void);

void	ft_put_image(char *texture, t_point p);
void	ft_put_sprite(char *texture, t_point p, int frame_index);

#endif