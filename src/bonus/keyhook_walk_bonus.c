/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_walk_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/19 15:52:35 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyhook.h"

static void	move_player(t_game *g, double dx, double dy)
{
	int		new_x;
	int		new_y;
	double	margin;

	margin = COLISSION;
	new_x = (int)(g->player.pos.x + dx + (dx > 0) * margin - (dx < 0) * margin);
	new_y = (int)(g->player.pos.y);
	if (new_x >= 0 && new_x < g->map.width && new_y >= 0
		&& new_y < g->map.height && g->map.matrix[new_y][new_x] != '1')
		g->player.pos.x += dx;
	new_x = (int)(g->player.pos.x);
	new_y = (int)(g->player.pos.y + dy + (dy > 0) * margin - (dy < 0) * margin);
	if (new_x >= 0 && new_x < g->map.width && new_y >= 0
		&& new_y < g->map.height && g->map.matrix[new_y][new_x] != '1')
		g->player.pos.y += dy;
}

void	walk_w(int key, t_game *g)
{
	if (key == KEY_W)
		move_player(g, g->player.dir.x * MOVE_SPEED, g->player.dir.y
			* MOVE_SPEED);
}

void	walk_s(int key, t_game *g)
{
	if (key == KEY_S)
		move_player(g, -g->player.dir.x * MOVE_SPEED, -g->player.dir.y
			* MOVE_SPEED);
}

void	walk_a(int key, t_game *g)
{
	if (key == KEY_A)
		move_player(g, -g->player.plane.x * MOVE_SPEED, -g->player.plane.y
			* MOVE_SPEED);
}

void	walk_d(int key, t_game *g)
{
	if (key == KEY_D)
		move_player(g, g->player.plane.x * MOVE_SPEED, g->player.plane.y
			* MOVE_SPEED);
}
