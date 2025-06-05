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

#include "mapdata.h"

// Read
int		ft_read(const char *path, t_mapdata *mapdata);

// Check_Map
int		ft_check_map(char **map, t_player *player);

// Flood_Fill
int		ft_flood_fill(char **map, int y, int x);

// Util
void	ft_init_mapdata(t_mapdata *mapdata);
void	ft_free_data(t_data *data);

#endif //MAPDATA_INT_H
