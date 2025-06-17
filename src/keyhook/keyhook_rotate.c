#include <math.h>
#include "keyhook.h"

void	rotate_view(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(angle)
		- game->player.dir.y * sin(angle);
	game->player.dir.y = old_dir_x * sin(angle)
		+ game->player.dir.y * cos(angle);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(angle)
		- game->player.plane.y * sin(angle);
	game->player.plane.y = old_plane_x * sin(angle)
		+ game->player.plane.y * cos(angle);
}
