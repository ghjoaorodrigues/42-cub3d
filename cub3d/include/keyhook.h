/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:40:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/13 06:19:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHOOK_H
#define KEYHOOK_H

#include "game.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

void	handle_input(t_game *game);

// Walk
void	walk_w(int keycode, t_game *game);
void	walk_s(int keycode, t_game *game);
void	walk_a(int keycode, t_game *game);
void	walk_d(int keycode, t_game *game);

// Rotate
void	rotate_view(t_game *game, double angle);

#endif //KEYHOOK_H
