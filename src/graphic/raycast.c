/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:08:28 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/18 14:44:28 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <tgmath.h>

void	calc_raydir(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->player.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->player.x) * ray->delta.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->player.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->player.y) * ray->delta.y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->horizontal_side = 0;
	ray->hit = 0;
	ray->camera_x = 2 * x / (double)game->win.width - 1;
	ray->ray_dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->ray_dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
	ray->player.y = game->player.pos.y;
	ray->player.x = game->player.pos.x;
	ray->map.y = (int)game->player.pos.y;
	ray->map.x = (int)game->player.pos.x;
	if (ray->ray_dir.x == 0)
		ray->delta.x = 1e30;
	else
		ray->delta.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta.y = 1e30;
	else
		ray->delta.y = fabs(1 / ray->ray_dir.y);
	ray->max_distance = 100.0;
}

void	ft_draw_line(t_game *game, int x)
{
	t_ray	ray;
	double	current_distance;

	init_ray(game, &ray, x);
	calc_raydir(&ray);
	current_distance = 0.0;
	while (ray.hit == 0 && current_distance < ray.max_distance)
	{
		calc_distance(&ray);
		current_distance += 1.0;
		if (ray.map.y >= 0 && ray.map.y < game->map.height && ray.map.x >= 0
			&& ray.map.x < game->map.width)
		{
			if (game->map.matrix[ray.map.y][ray.map.x] == '1')
				ray.hit = 1;
		}
		else if (current_distance > 50.0)
			break ;
	}
	if (ray.hit == 1)
	{
		calc_perp_dist(&ray);
		draw_walls(game, &ray, x);
	}
}

void	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while (x < game->win.width)
	{
		ft_draw_line(game, x);
		x++;
	}
}

void	draw_clf(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win.height / 2)
	{
		x = -1;
		while (++x < game->win.width)
			((unsigned int *)game->ray.addr)[y * (game->ray.line_len / 4)
				+ x] = 0x87CEEB;
		y++;
	}
	while (y < game->win.height)
	{
		x = -1;
		while (++x < game->win.width)
			((unsigned int *)game->ray.addr)[y * (game->ray.line_len / 4)
				+ x] = 0xA38C68;
		y++;
	}
}
