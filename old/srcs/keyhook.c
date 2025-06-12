/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/10 23:13:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int exit_game(t_game *game)
{
    mlx_loop_end(game->mlx_ptr);
    return (0);
}

int keyhook(int game->keycode, t_game *game)
{
    double new_x = game->pos_x;
    double new_y = game->pos_y;
    
    if (game->keycode == KEY_ESC)
    {
        mlx_loop_end(game->mlx_ptr);
        return (1);
    }
    if (game->keycode == KEY_W)
        new_y -= MOVE_SPEED;
    if (game->keycode == KEY_S)
        new_y += MOVE_SPEED;
    if (game->keycode == KEY_A)
        new_x -= MOVE_SPEED;
    if (game->keycode == KEY_D)
        new_x += MOVE_SPEED;
    if ((int)new_y >= 0 && (int)new_y < game->map_height &&
        (int)new_x >= 0 && game->map_copy_valid[(int)new_y] &&
        (int)new_x < (int)ft_strlen(game->map_copy_valid[(int)new_y]) &&
        game->map_copy_valid[(int)new_y][(int)new_x] != '1')
    {
        game->pos_x = new_x;
        game->pos_y = new_y;
    }
    printf("Player position: X=%f, Y=%f\n", game->pos_x, game->pos_y);
    dot_mover(game);
    return (0);
}
void	handle_input(t_game *game)
{
    mlx_hook(game->win_ptr, 2, 1L << 0, keyhook, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, exit_game, game);
}