/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/15 18:35:21 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	exit_game(t_game *game)
{
	if (game->ray_img)
		mlx_destroy_image(game->mlx.mlx, game->ray_img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	exit(0);
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
	walk_a(keycode, game);
	walk_s(keycode, game);
	walk_w(keycode, game);
	key_d(keycode, game);
	key_rotate_right(keycode, game);
	key_rotate_left(keycode, game);
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
