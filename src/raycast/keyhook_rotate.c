#include "../include/cube3d.h"

void	key_rotate_right(int keycode, t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == KEY_RIGHT)
	{
		oldDirX = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->rot_speed) - game->dir.y
			* sin(-game->rot_speed);
		game->dir.y = oldDirX * sin(-game->rot_speed) + game->dir.y
			* cos(-game->rot_speed);
		oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-game->rot_speed) - game->plane_y
			* sin(-game->rot_speed);
		game->plane_y = oldPlaneX * sin(-game->rot_speed) + game->plane_y
			* cos(-game->rot_speed);
	}
}

void	key_rotate_left(int keycode, t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == KEY_LEFT)
	{
		oldDirX = game->dir.x;
		game->dir.x = game->dir.x * cos(game->rot_speed) - game->dir.y
			* sin(game->rot_speed);
		game->dir.y = oldDirX * sin(game->rot_speed) + game->dir.y
			* cos(game->rot_speed);
		oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y
			* sin(game->rot_speed);
		game->plane_y = oldPlaneX * sin(game->rot_speed) + game->plane_y
			* cos(game->rot_speed);
	}
}
