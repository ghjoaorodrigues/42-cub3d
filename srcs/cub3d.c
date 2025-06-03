/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/03 16:19:26 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void setter_found(t_game *game)
{
	game->found_no = 0;
	game->found_ea = 0;
	game->found_we = 0;
	game->found_so = 0;
	game->found_f = 0;
	game->found_c = 0;
}
static int check_if_missing_identifiers(char **map, t_game *game)
{
	setter_found(game);
	int i;

	i = 0;
    while (map[i])
    {
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			game->found_no = 1;
		else if (ft_strncmp(map[i], "SO ", 3) == 0)
			game->found_so = 1;
		else if (ft_strncmp(map[i], "WE ", 3) == 0)
			game->found_we = 1;
		else if (ft_strncmp(map[i], "EA ", 3) == 0)
			game->found_ea = 1;
		else if (ft_strncmp(map[i], "F ", 2) == 0)
			game->found_f = 1;
		else if (ft_strncmp(map[i], "C ", 2) == 0)
			game->found_c = 1;
		i++;
	}
	if (game->found_no && game->found_ea &&
			game->found_f && game->found_c && game->found_we && game->found_so)
    	return (0);
	return(-1);
}

void	dot_mover(t_game *game)
{
	int	height;
	int	width;

	game->dot_img = mlx_xpm_file_to_image(game->mlx_ptr, DOT, &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->dot_img,
		(int)(game->pos_x * 20), (int)(game->pos_y * 20));
}
int	main(int argc, char **argv)
{
	t_game	game;
	char	**map_copy;

	if (argc != 2)
		return (ft_printf("./Usage cub3d map.cub\n"), 1);
	if (!is_mapber(argv[1]))
		return (1);
	if (parse_textures(argv[1], &game) == -1)
		return (1);
	load_map(argv[1], &game);
	if (error_check_playerdup(&game))
		return (1);
	if (check_if_missing_identifiers(game.map, &game) == -1)
		return (ft_printf("identifier missing\n"), 1);
	map_copy = dup_map(game.map, &game);
	game.map_copy_valid = dup_map(game.map, &game);
	find_playerpos(map_copy, &game.pos_x, &game.pos_y);
	if (flood_fill(map_copy, (int)game.pos_y, (int)game.pos_x))
		return (ft_printf("ERROR: MAP IS INVALID\n", 1));
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, HEIGHT, WIDTH, "CSGO");
	handle_input(&game);
	mlx_loop(game.mlx_ptr);
	cleanup_game(&game);
	free_mapcopy(map_copy);
	return (0);
}
