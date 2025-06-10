/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/10 16:47:53 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"


int exit_game(t_game *game)
{
    mlx_loop_end(game->mlx.mlx);
    return (0);
}

int keyhook(int keycode, t_game *game)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed = 0.05;
    
    if (keycode == KEY_ESC)
        exit_game(game);
    if (keycode == KEY_W)
    {
        if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x + game->dir.x * MOVE_SPEED)] != '1')
            game->pos_x += game->dir.x * MOVE_SPEED;
        if (game->map.matrix[(int)(game->pos_y + game->dir.y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y += game->dir.y * MOVE_SPEED;
    }
    if (keycode == KEY_S) // Move backward
    {
        if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x - game->dir.x * MOVE_SPEED)] != '1')
            game->pos_x -= game->dir.x * MOVE_SPEED;
        if (game->map.matrix[(int)(game->pos_y - game->dir.y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y -= game->dir.y * MOVE_SPEED;
    }
    
    // Strafe left/right
    if (keycode == KEY_A) // Strafe left
    {
        if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x - game->plane_x * MOVE_SPEED)] != '1')
            game->pos_x -= game->plane_x * MOVE_SPEED;
        if (game->map.matrix[(int)(game->pos_y - game->plane_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y -= game->plane_y * MOVE_SPEED;
    }
    if (keycode == KEY_D)
    {
        if (game->map.matrix[(int)(game->pos_y)][(int)(game->pos_x + game->plane_x * MOVE_SPEED)] != '1')
            game->pos_x += game->plane_x * MOVE_SPEED;
        if (game->map.matrix[(int)(game->pos_y + game->plane_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y += game->plane_y * MOVE_SPEED;
    }
    if (keycode == KEY_LEFT)
    {
        old_dir_x = game->dir.x;
        game->dir.x = game->dir.x * cos(rot_speed) - game->dir.y * sin(rot_speed);
        game->dir.y = old_dir_x * sin(rot_speed) + game->dir.y * cos(rot_speed);
        
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
    }
    if (keycode == KEY_RIGHT)
    {
        old_dir_x = game->dir.x;
        game->dir.x = game->dir.x * cos(-rot_speed) - game->dir.y * sin(-rot_speed);
        game->dir.y = old_dir_x * sin(-rot_speed) + game->dir.y * cos(-rot_speed);
        
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
    }
    draw_clf(game);
    raycasting(game);
    mlx_put_image_to_window(game->mlx.mlx, game->ray_win, game->ray_img, 0, 0);
    return (0);
}
void	handle_input(t_game *game)
{
    mlx_hook(game->ray_win, 2, 1L << 0, keyhook, game);
	mlx_hook(game->ray_win, 17, 1L << 17, exit_game, game);
}