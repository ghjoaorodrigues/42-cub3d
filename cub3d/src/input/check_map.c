/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:13:50 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:46:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "input_int.h"
#include <sys/cdefs.h>

int	ft_valid_char(const char c)
{
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

void	ft_set_player(t_player *player, t_vector dir, t_vector plane)
{
	player->dir.x = dir.x;
	player->dir.y = dir.y;
	player->plane.x = plane.x;
	player->plane.y = plane.y;
}

int	ft_player_pos(char *c, const int y, const int x, t_player *player)
{
	if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W')
	{
		if (player->pos.y != -1)
			return (1);
		player->pos.y = y + 0.5;
		player->pos.x = x + 0.5;
		if (*c == 'N')
			ft_set_player(player, (t_vector){0, -1}, (t_vector){-FOV, 0});
		else if (*c == 'E')
			ft_set_player(player, (t_vector){1, 0}, (t_vector){0, -FOV});
		else if (*c == 'S')
			ft_set_player(player, (t_vector){0, 1}, (t_vector){FOV, 0});
		else if (*c == 'W')
			ft_set_player(player, (t_vector){-1, 0}, (t_vector){0, FOV});
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
			if (ft_player_pos(&game->map.matrix[y][x], y, x,
				&game->player) != 0)
				return (ft_error("More than one player pos", E_PLAYER_DUP));
		}
	}
	if (game->player.pos.y == -1)
		return (ft_error("No player position given", E_NO_PLAYER));
	return (0);
}
