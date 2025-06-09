#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilibx-linux/mlx.h"
# include <math.h>

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

typedef struct s_game
{
	void	*mlx_win;
	void	*mlx_ptr;
	void	*img;
	double	pos_x;
	double	pos_y;
	char	*img_addr;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	ray_dirx;
	double	ray_diry;
	double	old_time;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltax;
	double	deltay;
	char	**map;
	void	*tex_so;
	void	*tex_no;
	void	*tex_ea;
	void	*tex_we;
	char	*tex_so_addr;
	char	*tex_no_addr;
	char	*tex_ea_addr;
	char	*tex_we_addr;
	int		tex_width;
	int		tex_height;
	int		tex_bpp;
	int		tex_line_len;
	int		bpp;
	int		line_len;
	int		mapx;
	int		mapy;
	int		horizontalside;
	int		hit;
	int		stepx;
	int		stepy;
	double	perpwalldist;
	int		line_height;
	int		draw_start;
	int		draw_end;

}			t_game;

int			keyhook(int keycode, t_game *game);
void		handle_input(t_game *game);
void		initi(t_game *game);

int			exit_game(t_game *game);
void		draw_clf(t_game *game);
void		raycasting(t_game *game);
void		alloc_map(t_game *game);
void		textures_set(t_game *game);
void		init_ray(t_game *game, int x);
void		calc_raydir(t_game *game);
void		calc_distance(t_game *game);
void		calc_perpdist(t_game *game);
void		draw_walls(t_game *game, int x);

#endif