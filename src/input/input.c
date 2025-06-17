/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:07:55 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 16:07:55 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_string.h"
#include "input.h"
#include "input_int.h"
#include "jal_memory.h"

int		ft_input(const char *path, t_game *game)
{
	if (ft_filename(path) != 0)
		return (1);
	if (ft_read(path, game) != 0)
		return (1);
	if (ft_check_map(game) != 0)
		return (1);
	if (ft_format_map(&game->map) != 0)
		return (1);
	if (ft_flood_fill(game->map.matrix, (int)game->player.pos.y, (int)game->player.pos.x) != 0)
		return (1);
	return (0);
}
