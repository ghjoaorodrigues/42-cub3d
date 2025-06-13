#include "../include/cube3d.h"

void	walk_w(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == KEY_W)
	{
		new_x = (int)(game->pos_x + game->dir.x * MOVE_SPEED);
		new_y = (int)(game->pos_y);
		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_x += game->dir.x * MOVE_SPEED;
		new_x = (int)(game->pos_x);
		new_y = (int)(game->pos_y + game->dir.y * MOVE_SPEED);
		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_y += game->dir.y * MOVE_SPEED;
	}
}

void	walk_s(int keycode, t_game *game)
{
	int new_x;
	int new_y;

	if (keycode == KEY_S)
	{
		new_x = (int)(game->pos_x - game->dir.x * MOVE_SPEED);
		new_y = (int)(game->pos_y);

		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_x -= game->dir.x * MOVE_SPEED;
		new_x = (int)game->pos_x;
		new_y = (int)game->pos_y - game->dir.y * MOVE_SPEED;
		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_y -= game->dir.y * MOVE_SPEED;
	}
}

void	walk_a(int keycode, t_game *game)
{
	int new_x;
	int new_y;

	if (keycode == KEY_A)
	{
		new_x = (int)(game->pos_x - game->plane_x * MOVE_SPEED);
		new_y = (int)(game->pos_y);

		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_x -= game->plane_x * MOVE_SPEED;
		new_x = (int)game->pos_x;
		new_y = (int)game->pos_y - game->plane_y * MOVE_SPEED;
		if (new_x >= 0 && new_x < game->map.width && new_y >= 0
			&& new_y < game->map.height
			&& game->map.matrix[new_y][new_x] != '1')
			game->pos_y -= game->plane_y * MOVE_SPEED;
	}
}