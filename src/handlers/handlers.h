/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:25:15 by vsoares-          #+#    #+#             */
/*   Updated: 2025/04/24 14:43:43 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../so_long.h"

# define CLOSE 17
# define ESCAPE 65307

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define W 119
# define S 115
# define A 97
# define D 100

int		close_window(void);
int		key_handler(int keycode);
int		mouse_handler(int mousecode, int x, int y);

void	move_up(void);
void	move_left(void);
void	move_down(void);
void	move_right(void);

bool	ft_ismovevalid(t_point p);
void    collect(t_point p);
void    exit_game(t_point p);

#endif