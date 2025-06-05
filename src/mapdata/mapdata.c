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
#include "jal_conversion.h"
#include "jal_gnl.h"
#include "jal_memory.h"
#include "jal_string.h"
#include "mapdata.h"
#include "mapdata_int.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_filename(const char *path)
{
	int	len;

	if (!*path)
		return (ft_error("Map path can't be empty", E_PATH_EMPTY));
	len = ft_strlen(path);
	if (len < 4 || ft_strcmp(path + len - 4, ".cub") != 0)
		return (ft_error("Wrong map file extension. Only '.cub' allowed",
				E_PATH_EXT));
	return (0);
}

int	ft_mapdata(const char *path, t_mapdata *mapdata)
{
	ft_init_mapdata(mapdata);
	if (ft_filename(path) != 0)
		return (1);
	if (ft_read(path, mapdata) != 0)
		return (1);
	if (ft_check_map(mapdata->map, &mapdata->player) != 0)
		return (ft_free_mapdata(mapdata), 1);
	if (ft_flood_fill(mapdata->map, mapdata->player.y, mapdata->player.x) != 0)
		return (ft_free_mapdata(mapdata), 1);
	return (0);
}
