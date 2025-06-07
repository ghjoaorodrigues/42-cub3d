/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:52:34 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/07 18:52:34 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"

void	test_print_game(t_game *game) {
	printf("TEST GAME\n");
	printf("map[%d][%d]:\n", game->map.height, game->map.width);
	for (int i = 0; i < game->map.height; i++)
		printf("|%s|\n", game->map.matrix[i]);
	printf("player vector: %.2f, %.2f\n", game->player.y, game->player.x);
	printf("dir vector: %.2f, %.2f\n", game->dir.y, game->dir.x);
}
