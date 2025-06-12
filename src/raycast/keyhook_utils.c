/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:08:37 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/11 20:08:37 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	front_back(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x + game->dir.x
				* MOVE_SPEED)] != '1')
			game->pos_x += game->dir.x * MOVE_SPEED;
		if (game->map.matrix[(int)(game->pos_y + game->dir.y
				* MOVE_SPEED)][(int)(game->pos_x)] != '1')
			game->pos_y += game->dir.y * MOVE_SPEED;
	}
	if (keycode == KEY_S) // Move backward
	{
		if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x - game->dir.x
				* MOVE_SPEED)] != '1')
			game->pos_x -= game->dir.x * MOVE_SPEED;
		if (game->map.matrix[(int)(game->pos_y - game->dir.y
				* MOVE_SPEED)][(int)(game->pos_x)] != '1')
			game->pos_y -= game->dir.y * MOVE_SPEED;
	}
}
void	strafe(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x
				- game->plane_x * MOVE_SPEED)] != '1')
			game->pos_x -= game->plane_x * MOVE_SPEED;
		if (game->map.matrix[(int)(game->pos_y - game->plane_y
				* MOVE_SPEED)][(int)(game->pos_x)] != '1')
			game->pos_y -= game->plane_y * MOVE_SPEED;
	}
	if (keycode == KEY_D)
	{
		if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x
				+ game->plane_x * MOVE_SPEED)] != '1')
			game->pos_x += game->plane_x * MOVE_SPEED;
		if (game->map.matrix[(int)(game->pos_y + game->plane_y
				* MOVE_SPEED)][(int)(game->pos_x)] != '1')
			game->pos_y += game->plane_y * MOVE_SPEED;
	}
}
void	left(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
	{
		game->old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(game->rot_speed) - game->dir.y
			* sin(game->rot_speed);
		game->dir.y = game->old_dir_x * sin(game->rot_speed) + game->dir.y
			* cos(game->rot_speed);
		game->old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y
			* sin(game->rot_speed);
		game->plane_y = game->old_plane_x * sin(game->rot_speed) + game->plane_y
			* cos(game->rot_speed);
	}
}

void	right(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
	{
		game->old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->rot_speed) - game->dir.y
			* sin(-game->rot_speed);
		game->dir.y = game->old_dir_x * sin(-game->rot_speed) + game->dir.y
			* cos(-game->rot_speed);
		game->old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-game->rot_speed) - game->plane_y
			* sin(-game->rot_speed);
		game->plane_y = game->old_plane_x * sin(-game->rot_speed)
			+ game->plane_y * cos(-game->rot_speed);
	}
}