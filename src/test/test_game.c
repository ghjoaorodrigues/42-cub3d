/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:52:34 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:55:23 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void	test_print_game(t_game *game)
{
	printf("TEST GAME\n");
	printf("N ptr: %p\n", game->map.n_texture);
	printf("E ptr: %p\n", game->map.e_texture);
	printf("S ptr: %p\n", game->map.s_texture);
	printf("W ptr: %p\n", game->map.w_texture);
	printf("F colour: %#X\n", game->map.f_colour);
	printf("C colour: %#X\n", game->map.c_colour);
	printf("map[%d][%d]:\n", game->map.height, game->map.width);
	for (int i = 0; i < game->map.height; i++)
		printf("|%s|\n", game->map.matrix[i]);
	printf("player vector: %.2f, %.2f\n", game->player.pos.y,
		game->player.pos.x);
	printf("dir vector: %.2f, %.2f\n", game->player.dir.y, game->player.dir.x);
	printf("plane vector: %.2f, %.2f\n", game->player.plane.y,
		game->player.plane.x);
}
