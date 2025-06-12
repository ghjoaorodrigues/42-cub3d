/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/11 20:09:15 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	exit_game(t_game *game)
{
	mlx_loop_end(game->mlx.mlx);
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	game->rot_speed = 0.05;
	if (keycode == KEY_ESC)
		exit_game(game);
	left(keycode, game);
	right(keycode, game);
	strafe(keycode, game);
	front_back(keycode, game);
	draw_clf(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx.mlx, game->ray_win, game->ray_img, 0, 0);
	return (0);
}

void	handle_input(t_game *game)
{
	mlx_hook(game->ray_win, 2, 1L << 0, keyhook, game);
	mlx_hook(game->ray_win, 17, 1L << 17, exit_game, game);
}
