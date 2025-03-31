/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:00:07 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/31 18:21:24 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(char *texture, int x, int y)
{
	t_image i;

	i.image = mlx_xpm_file_to_image(game()->mlx, texture, &i.width, &i.height);
	if(!i.image) exit(2);
	else mlx_put_image_to_window(game()->mlx, game()->win, i.image, 64 * x, 64 * y);
}
