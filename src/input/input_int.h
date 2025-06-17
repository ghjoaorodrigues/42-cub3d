/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdata_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:42:32 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 18:42:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_INT_H
#define MAPDATA_INT_H

#include "input.h"

// Filename
int		ft_filename(const char *path);

// Read
int		ft_read(const char *path, t_game *game);

// Check_Map
int		ft_check_map(t_game *game);

// Format Map
int		ft_format_map(t_map *map);

// Flood_Fill
int		ft_flood_fill(char **map, int y, int x);

#endif //MAPDATA_INT_H
