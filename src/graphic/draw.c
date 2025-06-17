/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:20:45 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/16 20:20:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "mlx.h"

void ft_draw(t_game *game) {
	game->ray.img = mlx_new_image(game->mlx, game->win.width, game->win.height);
	game->ray.addr = mlx_get_data_addr(game->ray.img, &game->ray.bpp,
			&game->ray.line_len, &game->ray.endian);
	draw_clf(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win.win, game->ray.img, 0, 0);
	mlx_destroy_image(game->mlx, game->ray.img);
}
