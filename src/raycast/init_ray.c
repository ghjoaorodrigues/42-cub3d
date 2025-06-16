/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:28:48 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/16 16:35:32 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	initi(t_game *game)
{
	game->pos_x = game->player.x;
	game->pos_y = game->player.y;
	if (game->dir.x == 1 && game->dir.y == 0)
	{ // East
		game->plane_x = 0;
		game->plane_y = -0.90;
	}
	else if (game->dir.x == -1 && game->dir.y == 0)
	{ // West
		game->plane_x = 0;
		game->plane_y = 0.90;
	}
	else if (game->dir.x == 0 && game->dir.y == 1)
	{
		game->plane_x = 0.90;
		game->plane_y = 0;
	}
	else if (game->dir.x == 0 && game->dir.y == -1)
	{
		game->plane_x = -0.90;
		game->plane_y = 0;
	}
	game->stepx = 0;
	game->stepy = 0;
}
void	ft_raycastmain(t_game *game)
{
	int endian;

	game->ray_win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT,
			"Hello world!");
	game->ray_img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	game->ray_addr = mlx_get_data_addr(game->ray_img, &game->bpp,
			&game->line_len, &endian);
	initi(game);
	textures_set(game);
	draw_clf(game);
	raycasting(game);
	handle_input(game);
	mlx_put_image_to_window(game->mlx.mlx, game->ray_win, game->ray_img, 0, 0);
}