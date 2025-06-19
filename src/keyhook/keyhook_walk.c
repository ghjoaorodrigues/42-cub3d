/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_walk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/19 15:09:50 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "graphic.h"
#include "keyhook.h"

static void	move_player(t_game *game, double dx, double dy)
{
	double	new_y;
	double	new_x;
	double	margin;

	new_y = game->player.pos.y;
	new_x = game->player.pos.x;
	margin = 0.3;
	if (dx != 0)
		new_x += dx * MOVE_SPEED;
	if (dy != 0)
		new_y += dy * MOVE_SPEED;
	if ((int)(new_y - margin) >= 0
		&& (int)(new_y + margin) < game->map.height
		&& (int)(new_x - margin) >= 0
		&& (int)(new_x + margin) < game->map.width)
	{
		game->player.pos.y = new_y;
		game->player.pos.x = new_x;
	}
}

void	walk_w(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, game->player.dir.x, game->player.dir.y);
}

void	walk_s(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		move_player(game, -game->player.dir.x, -game->player.dir.y);
}

void	walk_a(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_player(game, -game->player.plane.x, -game->player.plane.y);
}

void	walk_d(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		move_player(game, game->player.plane.x, game->player.plane.y);
}
