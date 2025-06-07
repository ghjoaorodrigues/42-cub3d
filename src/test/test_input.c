/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mapdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:21:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 17:21:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"

void	test_print_input(const t_input *input) {
	printf("TEST INPUT\n");
	printf("NO: %s\n", input->texture.NO);
	printf("SO: %s\n", input->texture.SO);
	printf("EA: %s\n", input->texture.EA);
	printf("WE: %s\n", input->texture.WE);
	printf("F: %d\n", input->texture.F);
	printf("C: %d\n", input->texture.C);
	printf("\n");
	printf("map:\n");
	for (int i = 0; input->map.matrix[i]; i++)
		printf("|%s|\n", input->map.matrix[i]);
	printf("player pos: y:%d, x:%d\n", input->player.y, input->player.x);
	printf("player direction: %d\n", input->player.direction);
}