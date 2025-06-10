/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/10 11:58:12 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "input.h"
#include "error.h"
#include "test.h"
#include "graphic.h"

int	main(int argc, char **argv)
{
	t_input	input;
	t_game	game;
	if (argc != 2)
		return (ft_error("Usage: ./cub3D <map_path>", E_ARGS));

	if (ft_input(argv[1], &input) != 0)
		return (*ft_exit_code());
	//test_print_input(&input);

	ft_init_game(&game, &input);
	ft_free_input(&input);

	test_print_game(&game);

	ft_graphic(&game);
	ft_raycastmain(&game);
	mlx_loop(game.mlx.mlx);
	

	ft_free_game(&game);

	return (0);
}
