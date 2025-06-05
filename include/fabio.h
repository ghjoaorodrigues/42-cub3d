/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:29:12 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/03 16:19:01 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307
#define HEIGHT 1920
#define WIDTH 1080
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define MOVE_SPEED 0.1
#define DOT "./assets/dot.xpm"

typedef struct s_game
{
	char **map;
	char **map_copy_valid;
	int player;
	void *mlx_ptr;
	void *win_ptr;
	char *NO;
	char *SO;
	char *EA;
	char *WE;
	double pos_y;
	double pos_x;
	double plane_x;
	double plane_y;
	double dir_x;
	double dir_y;
	int map_height;
	int map_width;
	int floor;
	int celing;
	int px;
	int py;
	int found_no;
	int found_ea;
	int found_we;
	int found_so;
	int found_f;
	int found_c;
	char *dot_img;
	int floor_color;
	int ceiling_color;
} t_game;

typedef struct s_minimap
{

} t_minimap;

//input
int keyhook(int keycode, t_game *game);
void handle_input(t_game *game);

int exit_game(t_game *game);
void free_map(t_game *game);
void alloc_map(t_game *game, int x, int y);
int load_map(char *filename, t_game *game);
void cleanup_game(t_game *game);
int is_mapline(char *line);
int ft_flood_fill(char **map, int x, int y);
void free_mapcopy(char **map);

//Check and validation
int is_mapber(char *filename);
int    check_playerdup(t_game *game);
char **dup_map(char **original, t_game *game);
int	parse_rgb(char *str);
int find_playerpos(char **map, double *px, double *py);
void dot_mover(t_game *game);
int error_check_playerdup(t_game *game);
int	parse_textures(char *filename, t_game *game);


#endif