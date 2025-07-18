/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:30:08 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:51:38 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "jal_memory.h"
#include "mlx.h"

void	ft_free_game(const t_game *game)
{
	if (game->map.matrix)
		ft_free_matrix((void **)game->map.matrix);
	if (game->map.n_texture)
		mlx_destroy_image(game->mlx, game->map.n_texture);
	if (game->map.e_texture)
		mlx_destroy_image(game->mlx, game->map.e_texture);
	if (game->map.s_texture)
		mlx_destroy_image(game->mlx, game->map.s_texture);
	if (game->map.w_texture)
		mlx_destroy_image(game->mlx, game->map.w_texture);
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
