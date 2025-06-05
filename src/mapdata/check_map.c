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

#include "error.h"
#include "mapdata_int.h"

int	ft_valid_char(char c) {
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_player_pos(char c, int y, int x, t_player *player) {
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W') {
		if (player->direction != -1)
			return (1);
		player->x = x;
		player->y = y;
		if (c == 'N')
			player->direction = 0;
		else if (c == 'E')
			player->direction = 1;
		else if (c == 'S')
			player->direction = 2;
		else if (c == 'W')
			player->direction = 3;
	}
	return (0);
}

int	ft_check_map(char **map, t_player *player)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_valid_char(map[y][x]))
				return (ft_error("Invalid char in map", E_INVALID_CHAR));
			if (ft_player_pos(map[y][x], y, x, player) != 0)
				return (ft_error("More than one player pos", E_PLAYER_DUP));
		}
	}
	if (player->direction == -1)
		return (ft_error("No player position given", E_NO_PLAYER));
	return (0);
}
