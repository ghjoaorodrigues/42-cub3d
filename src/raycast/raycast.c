/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:08:28 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/12 14:28:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
#include <stdio.h>

void	calc_raydir(t_game *game)
{
	if (game->ray_dirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->pos_x - game->mapx) * game->deltax;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - game->pos_x) * game->deltax;
	}
	if (game->ray_diry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->pos_y - game->mapy) * game->deltay;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - game->pos_y) * game->deltay;
	}
}

void	init_ray(t_game *game, int x)
{
	game->camerax = 2 * x / (double)WIDTH - 1;
	game->ray_dirx = game->dir.x + game->plane_x * game->camerax;
	game->ray_diry = game->dir.y + game->plane_y * game->camerax;
	game->mapx = (int)game->pos_x;
	game->mapy = (int)game->pos_y;
	if (game->ray_dirx == 0)
		game->deltax = 1e30;
	else
		game->deltax = fabs(1 / game->ray_dirx);
	if (game->ray_diry == 0)
		game->deltay = 1e30;
	else
		game->deltay = fabs(1 / game->ray_diry);
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		game->horizontalside = 0;
		game->hit = 0;
		init_ray(game, x);
		calc_raydir(game);
		while (game->hit == 0)
		{
			calc_distance(game);
			if (game->map.matrix[game->mapy][game->mapx] == '1')
				game->hit = 1;
		}
		if (game->hit == 1)
		{
			calc_perpdist(game);
			draw_walls(game, x);
		}
		x++;
	}
}

void	draw_clf(t_game *game)
{
	char	*adress;

	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			adress = game->ray_addr + (y * game->line_len + x * (game->bpp
						/ 8));
			*(unsigned int *)adress = 0x87CEEB;
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			adress = game->ray_addr + (y * game->line_len + x * (game->bpp
						/ 8));
			*(unsigned int *)adress = 0x228B22;
			x++;
		}
		y++;
	}
}
