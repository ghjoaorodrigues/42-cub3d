/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:21:17 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/10 17:25:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	calc_perpdist(t_game *game)
{
	if (game->horizontalside == 0)
		game->perpwalldist = (game->mapx - game->pos_x + (1 - game->stepx) / 2)
			/ game->ray_dirx;
	else
		game->perpwalldist = (game->mapy - game->pos_y + (1 - game->stepy) / 2)
			/ game->ray_diry;
}
void	calc_distance(t_game *game)
{
	if (game->sidedistx < game->sidedisty)
	{
		game->sidedistx += game->deltax;
		game->mapx += game->stepx;
		game->horizontalside = 0;
	}
	else
	{
		game->sidedisty += game->deltay;
		game->mapy += game->stepy;
		game->horizontalside = 1;
	}
}

char	*get_texture_addr(t_game *game)
{
	if (game->horizontalside == 0)
	{
		if (game->ray_dirx > 0)
			return (game->tex_we_addr);
		else
			return (game->tex_ea_addr);
	}
	else
	{
		if (game->ray_diry > 0)
			return (game->tex_no_addr);
		else
			return (game->tex_so_addr);
	}
}

void	draw_utils(t_game *game)
{
	game->line_height = (int)(HEIGHT / game->perpwalldist);
	game->draw_start = -game->line_height / 2 + HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + HEIGHT / 2;
	if (game->draw_end >= HEIGHT)
		game->draw_end = HEIGHT - 1;
	if (game->horizontalside == 0)
		game->wall_x = game->pos_y + game->perpwalldist * game->ray_diry;
	else
		game->wall_x = game->pos_x + game->perpwalldist * game->ray_dirx;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = (int)(game->wall_x * (double)game->tex_width);
	if ((game->horizontalside == 0 && game->ray_dirx > 0)
		|| (game->horizontalside == 1 && game->ray_diry < 0))
		game->tex_x = game->tex_width - game->tex_x - 1;
}
void	draw_walls(t_game *game, int x)
{
	int y;
	char *tex_addr;
	unsigned int color;
	int d;
	char *tex_pixel;
	char *dst;

	draw_utils(game);
	tex_addr = get_texture_addr(game);
	y = game->draw_start;
	while (y < game->draw_end)
	{
		d = y * 256 - HEIGHT * 128 + game->line_height * 128;
        
		game->tex_y = (d * game->tex_height) / game->line_height / 256;
		tex_pixel = tex_addr + (game->tex_y * game->tex_line_len + game->tex_x
				* (game->tex_bpp / 8));
		color = *(unsigned int *)tex_pixel;
		dst = game->ray_addr + (y * game->line_len + x * (game->bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}
