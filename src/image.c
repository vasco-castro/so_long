/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:00:07 by vsoares-          #+#    #+#             */
/*   Updated: 2025/03/07 21:16:51 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_put_image(void)
{
	t_image i;

	i.image = mlx_new_image(game()->mlx, 16, 16);
	i.address = mlx_get_data_addr(i.image, &i.bits_per_pixel, &i.size_line, &i.endian);
	ft_memcpy(i.address, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf",
	 ft_strlen("s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf"));
	i.width = 16;
	i.height = 16;
	//  memcpy(image_4x4.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);

	mlx_put_image_to_window(game()->mlx, game()->win, i.image, 720, 360);
}