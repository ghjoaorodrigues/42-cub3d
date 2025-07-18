/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:42:32 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:56:18 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_INT_H
# define INPUT_INT_H

# include "input.h"

// Filename
int	ft_filename(const char *path);

// Read
int	ft_read(const char *path, t_game *game);

// Check_Map
int	ft_check_map(t_game *game);

// Format Map
int	ft_format_map(t_map *map);

// Flood_Fill
int	ft_flood_fill(char **map, int y, int x);

#endif // INPUT_INT_H
