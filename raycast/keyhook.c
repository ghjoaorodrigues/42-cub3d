/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/09 20:08:37 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


int exit_game(t_game *game)
{
    mlx_loop_end(game->mlx_ptr);
    return (0);
}

int keyhook(int keycode, t_game *game)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed = 0.05;
    
    // ESC key to exit
    if (keycode == KEY_ESC)
        exit_game(game);
        
    // Movement keys
    if (keycode == KEY_W) // Move forward
    {
        if (game->map[(int)(game->pos_y)][(int)(game->pos_x + game->dir_x * MOVE_SPEED)] != '1')
            game->pos_x += game->dir_x * MOVE_SPEED;
        if (game->map[(int)(game->pos_y + game->dir_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y += game->dir_y * MOVE_SPEED;
    }
    if (keycode == KEY_S) // Move backward
    {
        if (game->map[(int)(game->pos_y)][(int)(game->pos_x - game->dir_x * MOVE_SPEED)] != '1')
            game->pos_x -= game->dir_x * MOVE_SPEED;
        if (game->map[(int)(game->pos_y - game->dir_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y -= game->dir_y * MOVE_SPEED;
    }
    
    // Strafe left/right
    if (keycode == KEY_A) // Strafe left
    {
        if (game->map[(int)(game->pos_y)][(int)(game->pos_x - game->plane_x * MOVE_SPEED)] != '1')
            game->pos_x -= game->plane_x * MOVE_SPEED;
        if (game->map[(int)(game->pos_y - game->plane_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y -= game->plane_y * MOVE_SPEED;
    }
    if (keycode == KEY_D) // Strafe right
    {
        if (game->map[(int)(game->pos_y)][(int)(game->pos_x + game->plane_x * MOVE_SPEED)] != '1')
            game->pos_x += game->plane_x * MOVE_SPEED;
        if (game->map[(int)(game->pos_y + game->plane_y * MOVE_SPEED)][(int)(game->pos_x)] != '1')
            game->pos_y += game->plane_y * MOVE_SPEED;
    }
    
    // Rotation keys
    if (keycode == KEY_LEFT) // Rotate left
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
        game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
        
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
    }
    if (keycode == KEY_RIGHT) // Rotate right
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
        game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
        
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
    }
    draw_clf(game);
    raycasting(game);
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img, 0, 0);
    return (0);
}
void	handle_input(t_game *game)
{
    mlx_hook(game->mlx_win, 2, 1L << 0, keyhook, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, exit_game, game);
}