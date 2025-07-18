/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:02:29 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:32:43 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "game.h"

typedef struct	s_ray {
	int			horizontal_side;
	int			hit;
	double		camera_x;
	t_vector	ray_dir;
	t_vector	player;
	t_point		map;
	t_vector	side_dist;
	t_vector	delta;
	t_point		step;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	t_point		tex;
}				t_ray;

// Draw
void			ft_draw(t_game *game);

// Raycast
void			draw_clf(t_game *game);
void			raycasting(t_game *game);

// Utils
void			calc_perp_dist(t_ray *ray);
void			calc_distance(t_ray *ray);
void			draw_walls(t_game *game, t_ray *ray, int x);

#endif //GRAPHIC_H
