/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:13:50 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 19:13:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>

#include "error.h"
#include "input_int.h"

int	ft_valid_char(const char c) {
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_player_pos(char *c, const int y, const int x, t_player *player) {
	if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W') {
		if (player->pos.y != -1)
			return (1);
		player->pos.y = y + 0.5;
		player->pos.x = x + 0.5;
		player->dir.y = 0;
		player->dir.x = 0;
		player->plane.y = 0;
		player->plane.x = 0;
		if (*c == 'N') {
			player->dir.y = -1;
			player->plane.x = -FOV;
		}
		else if (*c == 'E') {
			player->dir.x = 1;
			player->plane.y = -FOV;
		}
		else if (*c == 'S') {
			player->dir.y = 1;
			player->plane.x = FOV;
		}
		else if (*c == 'W') {
			player->dir.x = -1;
			player->plane.y = FOV;
		}
		*c = '0';
	}
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.matrix[++y])
	{
		x = -1;
		while (game->map.matrix[y][++x])
		{
			if (!ft_valid_char(game->map.matrix[y][x]))
				return (ft_error("Invalid char in map", E_INVALID_CHAR));
			if (ft_player_pos(&game->map.matrix[y][x], y, x, &game->player) != 0)
				return (ft_error("More than one player pos", E_PLAYER_DUP));
		}
	}
	if (game->player.pos.y == -1)
		return (ft_error("No player position given", E_NO_PLAYER));
	return (0);
}
