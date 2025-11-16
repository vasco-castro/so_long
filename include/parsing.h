/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:53:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/11/16 18:49:41 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"

# define PLAYER 'P'
# define WALL '1'
# define BACKGROUND '0'
# define COLLECTIBLE 'C'
# define ENEMY 'X'
# define EXIT 'E'

bool	get_map(char *map_path);
void	validate_map(void);
void	flood_fill(char *map[], t_point p);

#endif