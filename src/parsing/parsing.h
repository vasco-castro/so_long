/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:53:37 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 19:16:50 by vsoares-         ###   ########.fr       */
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

bool	flood_fill(char *map[], t_point p);
bool	parse_map(char *map_path);


void	parse_check(void);
char	**read_map(int fd, size_t i);
bool	get_map(char *map_path);

#endif