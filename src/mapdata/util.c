/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:41:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 18:41:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "jal_memory.h"
#include "mapdata_int.h"

void	ft_init_mapdata(t_mapdata *mapdata) {
	mapdata->data.NO = NULL;
	mapdata->data.SO = NULL;
	mapdata->data.EA = NULL;
	mapdata->data.WE = NULL;
	mapdata->data.F = -1;
	mapdata->data.C = -1;
	mapdata->map = NULL;
	mapdata->player.x = -1;
	mapdata->player.y = -1;
	mapdata->player.direction = -1;
}

void	ft_free_data(t_data *data) {
	if (data->NO)
		free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->EA)
		free(data->EA);
	if (data->WE)
		free(data->WE);
}

void	ft_free_mapdata(t_mapdata *mapdata) {
	ft_free_data(&mapdata->data);
	ft_free_matrix((void **)mapdata->map);
}
