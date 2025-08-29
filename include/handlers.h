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

# define CLOSE_KEY 17
# define ESCAPE_KEY 65307
# define ESCAPE_KEY_DARWIN 53

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

# define UP_KEY_DARWIN 126
# define DOWN_KEY_DARWIN 125
# define LEFT_KEY_DARWIN 123
# define RIGHT_KEY_DARWIN 124

# define W_KEY_DARWIN 13
# define S_KEY_DARWIN 1
# define A_KEY_DARWIN 0
# define D_KEY_DARWIN 2

int		close_window(void);
int		key_handler(int keycode);
int		mouse_handler(int mousecode, int x, int y);

void	move_up(void);
void	move_left(void);
void	move_down(void);
void	move_right(void);

void	move(t_point new_position);

#endif