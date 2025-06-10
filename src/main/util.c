/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:10:57 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/10 16:50:40 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "input.h"
#include "jal_memory.h"

void	ft_free_game(t_game *game) {
	ft_free_matrix((void **)game->map.matrix);
}

void	ft_direction(t_game *game, const struct s_input *input) {
	game->map.height = input->map.height;
	game->map.width = input->map.width;
	game->map.matrix = input->map.matrix;
	game->player.x = input->player.x + 0.5;
	game->player.y = input->player.y + 0.5;
	game->dir.x = 0;
	game->dir.y = 0;
	if (input->player.direction == 0)
		game->dir.y = 1;
	else if (input->player.direction == 1)
		game->dir.x = 1;
	else if (input->player.direction == 2)
		game->dir.y = -1;
	else if (input->player.direction == 3)
		game->dir.x = -1;
}

void	ft_init_game(t_game *game, const struct s_input *input) {
	ft_direction(game, input);
}
