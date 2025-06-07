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

typedef struct	s_texture {
	char		*NO;
	char		*SO;
	char		*EA;
	char		*WE;
	int			F;
	int			C;
}				t_texture;

typedef struct	s_imap {
	char		**matrix;
	int			height;
	int			width;
}				t_imap;

typedef struct	s_player {
	int	x;
	int	y;
	int	direction;
}				t_player;

typedef struct	s_input {
	t_texture	texture;
	t_imap		map;
	t_player	player;
}				t_input;

int		ft_input(const char *path, t_input *input);
void	ft_free_input(t_input *input);

#endif //MAP_H
