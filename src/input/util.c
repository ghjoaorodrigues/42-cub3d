/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:41:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/10 14:30:36 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input_int.h"

void	ft_init_input(t_input *input) {
	input->texture.NO = NULL;
	input->texture.SO = NULL;
	input->texture.EA = NULL;
	input->texture.WE = NULL;
	input->texture.F = -1;
	input->texture.C = -1;
	input->map.matrix = NULL;
	input->player.x = -1;
	input->player.y = -1;
	input->player.direction = -1;
}

void	ft_free_texture(const t_texture *texture) {
	if (texture->NO)
		free(texture->NO);
	if (texture->SO)
		free(texture->SO);
	if (texture->EA)
		free(texture->EA);
	if (texture->WE)
		free(texture->WE);
}
