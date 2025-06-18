/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_walk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/18 14:09:21 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyhook.h"

static void	move_player(t_game *game, double dx, double dy)
{
	if (dx != 0)
		game->player.pos.x += dx * MOVE_SPEED;
	if (dy != 0)
		game->player.pos.y += dy * MOVE_SPEED;
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
