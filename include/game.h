/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:18:28 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/16 20:34:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#define FOV 0.9
#define TEXTURE_SIZE 512

#define	WIN_HEIGHT 720
#define	WIN_RATIO 16/9

#define ROT_SPEED 0.025
#define MOVE_SPEED 0.06

#include "vector.h"

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			width;
	void		*n_texture;
	void		*e_texture;
	void		*s_texture;
	void		*w_texture;
	int			f_colour;
	int			c_colour;
}				t_map;

typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct s_win
{
	void		*win;
	int			height;
	int			width;
}				t_win;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			tile_size;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_keys {
	int 		w;
	int 		a;
	int 		s;
	int 		d;
	int 		left;
	int 		right;
}				t_keys;

typedef struct	s_game
{
	t_map		map;
	t_player	player;
	void		*mlx;
	t_win		win;
	t_img		ray;
	t_keys		keys;
}				t_game;

// Init
int				ft_init(t_game *game);
// Free
void			ft_free_game(const t_game *game);

#endif //GAME_H
