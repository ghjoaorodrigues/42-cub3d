/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/18 14:18:19 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "keyhook.h"
#include "mlx.h"
#include <stdlib.h>

int	exit_game(t_game *game)
{
	ft_free_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		game->keys.w = 1;
	if (keycode == KEY_A)
		game->keys.a = 1;
	if (keycode == KEY_S)
		game->keys.s = 1;
	if (keycode == KEY_D)
		game->keys.d = 1;
	if (keycode == KEY_LEFT)
		game->keys.left = 1;
	if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	if (keycode == KEY_A)
		game->keys.a = 0;
	if (keycode == KEY_S)
		game->keys.s = 0;
	if (keycode == KEY_D)
		game->keys.d = 0;
	if (keycode == KEY_LEFT)
		game->keys.left = 0;
	if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

int	update(t_game *game)
{
	if (game->keys.w)
		walk_w(KEY_W, game);
	if (game->keys.a)
		walk_a(KEY_A, game);
	if (game->keys.s)
		walk_s(KEY_S, game);
	if (game->keys.d)
		walk_d(KEY_D, game);
	if (game->keys.left)
		rotate_view(game, ROT_SPEED);
	if (game->keys.right)
		rotate_view(game, -ROT_SPEED);
	ft_draw(game);
	return (0);
}

void	handle_input(t_game *game)
{
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	mlx_hook(game->win.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win.win, 17, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, update, game);
}
