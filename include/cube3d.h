/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:47:07 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 18:47:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#define DEBUG 1

typedef struct s_vector {
	double		x;
	double		y;
}				t_vector;

typedef struct	s_map {
	char		**matrix;
	int			height;
	int			width;
}				t_map;

typedef struct	s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_game {
	t_map		map;
	t_vector	player;
	t_vector	dir;
	t_mlx		mlx;
}				t_game;

// Init
struct	s_input;
void	ft_init_game(t_game *game, const struct s_input *input);
void	ft_free_game(t_game *game);

#endif //CUBE3D_H
