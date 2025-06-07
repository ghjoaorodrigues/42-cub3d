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
int		ft_read(const char *path, t_input *input);

// Check_Map
int		ft_check_map(char **map, t_player *player);

// Format Map
int		ft_format_map(t_imap *map);

// Flood_Fill
int		ft_flood_fill(char **map, int y, int x);

// Util
void	ft_init_input(t_input *input);
void	ft_free_texture(const t_texture *texture);

#endif //MAPDATA_INT_H
