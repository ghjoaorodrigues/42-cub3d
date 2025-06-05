/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:57:23 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/05/28 18:26:55 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void cleanup_game(t_game *game)
{
	if (game->NO)
		free(game->NO);
	if (game->SO)
		free(game->SO);
	if (game->WE)
		free(game->WE);
	if (game->EA)
		free(game->EA);
    	if (game->map)
        	free_map(game);
	if (game->map_copy_valid)
		free_mapcopy(game->map_copy_valid);
	if (game->win_ptr)
        	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
        	mlx_destroy_display(game->mlx_ptr);
    		free(game->mlx_ptr);
	}
}
