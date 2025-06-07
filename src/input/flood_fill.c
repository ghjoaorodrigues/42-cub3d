/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:42:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 19:42:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_error.h"
#include "jal_memory.h"
#include "jal_string.h"
#include "input_int.h"

static int is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'F' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_surronded_by_valid(char **map, int y, int x)
{
	return (is_valid_map_char(map[y - 1][x])
		&& is_valid_map_char(map[y + 1][x])
		&& is_valid_map_char(map[y][x - 1])
		&& is_valid_map_char(map[y][x + 1]));
}

int ft_r_flood_fill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '\n' || map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if ((map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'N')
			&& (y < 1
			|| !map[y + 1]
			|| x < 1
			|| (!map[y][x + 1] || map[y][x + 1] == '\n')
			|| !is_surronded_by_valid(map, y, x)))
				return (1);
	map[y][x] = 'F';
	if (ft_r_flood_fill(map, y + 1, x))
		return (1);
	if (ft_r_flood_fill(map, y - 1, x))
		return (1);
	if (ft_r_flood_fill(map, y, x + 1))
		return (1);
	if (ft_r_flood_fill(map,y,x - 1))
		return (1);
	return (0);
}

int ft_flood_fill(char **map, int y, int x) {
	char	**map_dup;

	map_dup = ft_strarrdup(map);
	if (!map_dup)
		return (ft_error("Memory allocation failed", E_NOMEM));
	if (ft_r_flood_fill(map_dup, y, x) != 0)
		return (ft_free_matrix((void **)map_dup), ft_error("Map is not fully surronded by walls", E_MAP_SURRONDED));
	ft_free_matrix((void **)map_dup);
	return (0);
}
