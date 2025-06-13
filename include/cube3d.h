/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:47:07 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/13 16:32:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define DEBUG 1
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define WIDTH 1600
# define HEIGHT 900
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define MOVE_SPEED 0.1
# define WALL_INVISIBILITY 0.3

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			width;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_game
{
	t_map		map;
	t_vector	player;
	t_vector	dir;
	t_mlx		mlx;
	void		*img;
	double		pos_x;
	double		pos_y;
	char		*img_addr;
	double		plane_x;
	double		plane_y;
	double		time;
	double		ray_dirx;
	double		ray_diry;
	double		old_time;
	double		camerax;
	double		sidedistx;
	double		sidedisty;
	double		deltax;
	double		deltay;
	void		*tex_so;
	void		*tex_no;
	void		*tex_ea;
	void		*tex_we;
	char		*tex_so_addr;
	char		*tex_no_addr;
	char		*tex_ea_addr;
	char		*tex_we_addr;
	int			tex_width;
	int			tex_height;
	int			tex_bpp;
	int			tex_line_len;
	int			bpp;
	int			line_len;
	int			mapx;
	int			mapy;
	int			horizontalside;
	int			hit;
	int			stepx;
	int			stepy;
	double		perpwalldist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	void		*ray_win;
	void		*ray_img;
	char		*ray_addr;
	double		wall_x;
	int			tex_y;
	int			tex_x;
	double		old_dir_x;
	double		old_plane_x;
	double		rot_speed;
	int			new_x;
	int			new_y;

}				t_game;

// Init
struct s_input;
void			ft_init_game(t_game *game, const struct s_input *input);
void			ft_free_game(t_game *game);
int				keyhook(int keycode, t_game *game);
void			handle_input(t_game *game);
void			initi(t_game *game);

int				exit_game(t_game *game);
void			draw_clf(t_game *game);
void			raycasting(t_game *game);
void			textures_set(t_game *game);
void			init_ray(t_game *game, int x);
void			calc_raydir(t_game *game);
void			calc_distance(t_game *game);
void			calc_perpdist(t_game *game);
void			draw_walls(t_game *game, int x);
void			ft_raycastmain(t_game *game);
void			draw_utils(t_game *game);
char			*get_texture_addr(t_game *game);
void			right(int keycode, t_game *game);
void			left(int keycode, t_game *game);
void			strafe(int keycode, t_game *game);
void			front_back(int keycode, t_game *game);
void			walk_w(int keycode, t_game *game);
void			walk_s(int keycode, t_game *game);
void	walk_a(int keycode, t_game *game);
#endif // CUBE3D_H
