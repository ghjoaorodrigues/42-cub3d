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
	t_vector	new;
	t_vector	try;
	double		margin;

	new.y = game->player.pos.y;
	new.x = game->player.pos.x;
	margin = 0.2;
	if (dx != 0)
	{
		try.x = new.x + dx * MOVE_SPEED;
		if (game->map.matrix[(int)new.y][(int)(try.x + margin)] != '1'
			&& game->map.matrix[(int)new.y][(int)(try.x - margin)] != '1')
			game->player.pos.x = try.x;
	}
	if (dy != 0)
	{
		try.y = new.y + dy * MOVE_SPEED;
		if (game->map.matrix[(int)(try.y + margin)][(int)(new.x)] != '1'
			&& game->map.matrix[(int)(try.y - margin)][(int)(new.x)] != '1')
			game->player.pos.y = try.y;
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
