#include "keyhook.h"
#define COLISSION 0.3

static void move_player(t_game *game, double dx, double dy) {
	//int new_x, new_y;

	// X movement
	if (dx != 0)
		game->player.pos.x += dx * MOVE_SPEED;
	// Y movement
	if (dy != 0)
		game->player.pos.y += dy * MOVE_SPEED;

	// // X movement
	// if (dx != 0) {
	// 	if (dx > 0)
	// 		new_x = (int)(game->player.pos.x + dx * MOVE_SPEED + COLISSION);
	// 	else
	// 		new_x = (int)(game->player.pos.x + dx * MOVE_SPEED - COLISSION);
	// 	new_y = (int)(game->player.pos.y);
	// 	if (new_x >= 0 && new_x < game->map.width && new_y >= 0
	// 		&& new_y < game->map.height
	// 		&& game->map.matrix[new_y][new_x] != '1')
	// 		game->player.pos.x += dx * MOVE_SPEED;
	// }
	//
	// // Y movement
	// if (dy != 0) {
	// 	new_x = (int)(game->player.pos.x);
	// 	if (dy > 0)
	// 		new_y = (int)(game->player.pos.y + dy * MOVE_SPEED + COLISSION);
	// 	else
	// 		new_y = (int)(game->player.pos.y + dy * MOVE_SPEED - COLISSION);
	// 	if (new_x >= 0 && new_x < game->map.width && new_y >= 0
	// 		&& new_y < game->map.height
	// 		&& game->map.matrix[new_y][new_x] != '1')
	// 		game->player.pos.y += dy * MOVE_SPEED;
	// }
}

void walk_w(int keycode, t_game *game) {
	if (keycode == KEY_W)
		move_player(game, game->player.dir.x, game->player.dir.y);
}
void walk_s(int keycode, t_game *game) {
	if (keycode == KEY_S)
		move_player(game, -game->player.dir.x, -game->player.dir.y);
}
void walk_a(int keycode, t_game *game) {
	if (keycode == KEY_A)
		move_player(game, -game->player.plane.x, -game->player.plane.y);
}
void walk_d(int keycode, t_game *game) {
	if (keycode == KEY_D)
		move_player(game, game->player.plane.x, game->player.plane.y);
}