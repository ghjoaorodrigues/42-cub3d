/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:05:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 18:56:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

typedef struct	s_data {
	char		*NO;
	char		*SO;
	char		*EA;
	char		*WE;
	int			F;
	int			C;
}				t_data;

typedef struct	s_player {
	int	x;
	int	y;
	int	direction;
}				t_player;

typedef struct	s_mapdata {
	t_data		data;
	char		**map;
	t_player	player;
}				t_mapdata;

int		ft_mapdata(const char *path, t_mapdata *mapdata);
void	ft_free_mapdata(t_mapdata *mapdata);

#endif //MAP_H
