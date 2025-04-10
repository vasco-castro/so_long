/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:53:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/10 20:54:11 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define PLAYER 'P'
# define WALL '1'
# define BACKGROUND '0'
# define COLLECTIBLE 'C'
# define ENEMY 'X'
# define EXIT 'E'

bool	flood_fill(void);
bool	parse_map(char *map_path);

#endif