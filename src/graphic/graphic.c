/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:03:23 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/07 20:03:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "mlx.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

t_img	ft_square(const t_mlx *mlx, int size, int border_colour, int fill_colour)
{
	t_img	image;
	int		y;
	int		x;
	int		colour;

	image.img = mlx_new_image(mlx->mlx, size, size);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			colour = fill_colour;
			if (x == 0 || x == size - 1 || y == 0 || y == size - 1)
				colour = border_colour;
			((unsigned int *)image.addr)[y * (image.line_len / 4) + x] = colour;
			x++;
		}
		y++;
	}
	return (image);
}

void	ft_draw_map(const t_mlx *mlx, const t_map *map) {
	int		square_size;
	t_img	floor;
	t_img	wall;
	int		y;
	int		x;

	if (map->height > map->width)
		square_size = DEBUG_WIN_HEIGHT / map->height;
	else
		square_size = DEBUG_WIN_WIDTH / map->width;
	floor = ft_square(mlx, square_size, 0x111111, 0x000000);
	wall = ft_square(mlx, square_size, 0xAAAAAA, 0xFFFFFF);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->matrix[y][x] != '1' && map->matrix[y][x] != ' ')
				mlx_put_image_to_window(mlx->mlx, mlx->win, floor.img, x * square_size, y * square_size);
			if (map->matrix[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, wall.img, x * square_size, y * square_size);
		}
	}
}

void	ft_init_mlx(t_mlx *mlx) {
	int	height;
	int	width;

	height = WIN_HEIGHT;
	width = WIN_WIDTH;
	if (DEBUG) {
		height += DEBUG_WIN_HEIGHT;
		width += DEBUG_WIN_WIDTH;
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, "cub3D");
}

void	ft_graphic(t_game *game) {
	ft_init_mlx(&game->mlx);
	ft_draw_map(&game->mlx, &game->map);
	mlx_loop(game->mlx.mlx);
}
