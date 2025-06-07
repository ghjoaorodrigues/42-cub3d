/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:07:55 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 16:07:55 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_string.h"
#include "input.h"
#include "input_int.h"
#include "jal_memory.h"

void	ft_free_input(t_input *input) {
	ft_free_texture(&input->texture);
	//ft_free_matrix((void **)input->map.matrix);
}

int	ft_input(const char *path, t_input *input)
{
	ft_init_input(input);
	if (ft_filename(path) != 0)
		return (1);
	if (ft_read(path, input) != 0)
		return (1);
	if (ft_check_map(input->map.matrix, &input->player) != 0)
		return (ft_free_input(input), 1);
	if (ft_format_map(&input->map) != 0)
		return (ft_free_input(input), 1);
	if (ft_flood_fill(input->map.matrix, input->player.y, input->player.x) != 0)
		return (ft_free_input(input), 1);
	return (0);
}
