/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/13 16:43:19 by fsilva-p         ###   ########.fr       */
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
	int	endian;

	mlx_destroy_image(game->mlx.mlx, game->ray_img);
	game->ray_img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	game->ray_addr = mlx_get_data_addr(game->ray_img, &game->bpp,
			&game->line_len, &endian);
	game->rot_speed = 0.05;
	if (keycode == KEY_ESC)
		exit_game(game);
	walk_a(keycode,game);
	walk_s(keycode, game);
	walk_w(keycode,game);
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
