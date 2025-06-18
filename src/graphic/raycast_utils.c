/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:21:17 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/18 14:44:47 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "mlx.h"
#include <math.h>

void	calc_perp_dist(t_ray *ray)
{
	if (ray->horizontal_side == 0)
		ray->perp_wall_dist = (ray->map.x - ray->player.x + (1 - ray->step.x)
				/ 2) / ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - ray->player.y + (1 - ray->step.y)
				/ 2) / ray->ray_dir.y;
}

void	calc_distance(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta.x;
		ray->map.x += ray->step.x;
		ray->horizontal_side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta.y;
		ray->map.y += ray->step.y;
		ray->horizontal_side = 1;
	}
}

void	get_texture_addr(t_game *game, t_ray *ray, t_img *tex_img)
{
	if (ray->horizontal_side == 0)
	{
		if (ray->ray_dir.x > 0)
			tex_img->img = game->map.w_texture;
		else
			tex_img->img = game->map.e_texture;
	}
	else
	{
		if (ray->ray_dir.y > 0)
			tex_img->img = game->map.n_texture;
		else
			tex_img->img = game->map.s_texture;
	}
	tex_img->addr = mlx_get_data_addr(tex_img->img, &tex_img->bpp,
			&tex_img->line_len, &tex_img->endian);
}

void	draw_utils(t_game *game, t_ray *ray)
{
	ray->line_height = (int)(game->win.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->win.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->win.height / 2;
	if (ray->draw_end >= game->win.height)
		ray->draw_end = game->win.height - 1;
	if (ray->horizontal_side == 0)
		ray->wall_x = ray->player.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = ray->player.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex.x = (int)(ray->wall_x * (double)TEXTURE_SIZE);
	if ((ray->horizontal_side == 0 && ray->ray_dir.x > 0)
		|| (ray->horizontal_side == 1 && ray->ray_dir.y < 0))
		ray->tex.x = TEXTURE_SIZE - ray->tex.x - 1;
}

void	draw_walls(t_game *game, t_ray *ray, int x)
{
	int				y;
	t_img			tex_img;
	int				d;
	unsigned int	color;

	draw_utils(game, ray);
	get_texture_addr(game, ray, &tex_img);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		d = y * 256 - game->win.height * 128 + ray->line_height * 128;
		ray->tex.y = (d * TEXTURE_SIZE) / ray->line_height / 256;
		color = ((unsigned int *)tex_img.addr)[ray->tex.y * (tex_img.line_len
				/ 4) + ray->tex.x];
		((unsigned int *)game->ray.addr)[y * (game->ray.line_len / 4)
			+ x] = color;
		y++;
	}
}
