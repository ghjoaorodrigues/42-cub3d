#include "raycasting.h"
#include <stdio.h>

static char	*get_texture_addr(t_game *g)
{
	if (g->horizontalside == 0)
	{
		if (g->ray_dirx > 0)
			return g->tex_we_addr;
		else
			return g->tex_ea_addr;
	}
	else
	{
		if (g->ray_diry > 0)
			return g->tex_no_addr;
		else
			return g->tex_so_addr;
	}
}

void	draw_walls(t_game *g, int x)
{
	int		y;
	double	wallX;
	int		texX, texY;
	char	*tex_addr;
	unsigned int color;

	g->line_height = (int)(HEIGHT / g->perpwalldist);
	g->draw_start = -g->line_height / 2 + HEIGHT / 2;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_height / 2 + HEIGHT / 2;
	if (g->draw_end >= HEIGHT)
		g->draw_end = HEIGHT - 1;

	// 1. Calcula o ponto de colisão na parede
	if (g->horizontalside == 0)
		wallX = g->pos_y + g->perpwalldist * g->ray_diry;
	else
		wallX = g->pos_x + g->perpwalldist * g->ray_dirx;
	wallX -= floor(wallX);

	// 2. Converte para coordenada X da textura
	texX = (int)(wallX * (double)g->tex_width);
	if ((g->horizontalside == 0 && g->ray_dirx > 0) || (g->horizontalside == 1 && g->ray_diry < 0))
		texX = g->tex_width - texX - 1;

	// 3. Pega o endereço da textura
	tex_addr = get_texture_addr(g);

	// 4. Desenha a coluna da parede com base na textura
	y = g->draw_start;
	while (y < g->draw_end)
	{
		int d = y * 256 - HEIGHT * 128 + g->line_height * 128;
		texY = (d * g->tex_height) / g->line_height / 256;

		char *tex_pixel = tex_addr + (texY * g->tex_line_len + texX * (g->tex_bpp / 8));
		color = *(unsigned int *)tex_pixel;

		char *dst = g->img_addr + (y * g->line_len + x * (g->bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}

void	calc_perpdist(t_game *game)
{
	if (game->horizontalside == 0)
		game->perpwalldist = (game->mapx - game->pos_x + (1 - game->stepx) / 2)
			/ game->ray_dirx;
	else
		game->perpwalldist = (game->mapy - game->pos_y + (1 - game->stepy) / 2)
			/ game->ray_diry;
}
void	calc_distance(t_game *game)
{
	if (game->sidedistx < game->sidedisty)
	{
		game->sidedistx += game->deltax;
		game->mapx += game->stepx;
		game->horizontalside = 0;
	}
	else
	{
		game->sidedisty += game->deltay;
		game->mapy += game->stepy;
		game->horizontalside = 1;
	}
}
void	calc_raydir(t_game *game)
{
	if (game->ray_dirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->pos_x - game->mapx) * game->deltax;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - game->pos_x) * game->deltax;
	}
	if (game->ray_diry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->pos_y - game->mapy) * game->deltay;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - game->pos_y) * game->deltay;
	}
}
void	init_ray(t_game *game, int x)
{
	game->camerax = 2 * x / (double)WIDTH - 1;
	game->ray_dirx = game->dir_x + game->plane_x * game->camerax;
	game->ray_diry = game->dir_y + game->plane_y * game->camerax;
	game->mapx = (int)game->pos_x;
	game->mapy = (int)game->pos_y;
	if (game->ray_dirx == 0)
		game->deltax = 1e30;
	else
		game->deltax = fabs(1 / game->ray_dirx);
	if (game->ray_diry == 0)
		game->deltay = 1e30;
	else
		game->deltay = fabs(1 / game->ray_diry);
}
void	alloc_map(t_game *game)
{
	static char	*map_data[] = {"1111111111", "1000000001", "1000000001",
			"1000000001", "1000000001", "1111111111"};

	game->map = map_data;
}
void	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		game->horizontalside = 0;
		game->hit = 0;
		init_ray(game, x);
		calc_raydir(game);
		while (game->hit == 0)
		{
			calc_distance(game);
			if (game->map[game->mapy][game->mapx] == '1')
				game->hit = 1;
		}
		if (game->hit == 1)
		{
			calc_perpdist(game);
			draw_walls(game, x);
		}
		x++;
	}
}

void	draw_clf(t_game *game)
{
	char	*adress;

	int x, y;
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			adress = game->img_addr + (y * game->line_len + x * (game->bpp
						/ 8));
			*(unsigned int *)adress = 0x87CEEB;
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			adress = game->img_addr + (y * game->line_len + x * (game->bpp
						/ 8));
			*(unsigned int *)adress = 0x228B22;
			x++;
		}
		y++;
	}
}
void	initi(t_game *game)
{
	game->pos_x = 5.0;
	game->pos_y = 3.0;
	game->dir_x = -1;
	game->dir_y = 0;
	game->time = 0;
	game->old_time = 0;
	game->plane_x = 0;
	game->plane_y = 0.66; // FOV
	game->stepx = 0;
	game->stepy = 0;
}
int	main(void)
{
	t_game game;
	int endian;
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "Hello world!");
	game.img = mlx_new_image(game.mlx_ptr, WIDTH, HEIGHT);
	game.img_addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_len,
			&endian);
	initi(&game);
	alloc_map(&game);
	textures_set(&game);
	draw_clf(&game);
	raycasting(&game);
	mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.img, 0, 0);
	handle_input(&game);
	mlx_loop(game.mlx_ptr);
}