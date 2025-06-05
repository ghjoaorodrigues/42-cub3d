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

void	test_print_map_data(t_mapdata *mapdata) {
	printf("NO: %s\n", mapdata->data.NO);
	printf("SO: %s\n", mapdata->data.SO);
	printf("EA: %s\n", mapdata->data.EA);
	printf("WE: %s\n", mapdata->data.WE);
	printf("F: %d\n", mapdata->data.F);
	printf("C: %d\n", mapdata->data.C);
	printf("\n");
	printf("map:\n");
	for (int i = 0; mapdata->map[i]; i++)
		printf("%s\n", mapdata->map[i]);
	printf("player pos: y:%d, x:%d\n", mapdata->player.y, mapdata->player.x);
	printf("player direction: %d\n", mapdata->player.direction);
}