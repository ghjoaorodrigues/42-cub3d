/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:08:25 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/16 16:36:19 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	textures_set(t_game *game)
{
	int	endian;

	game->tex_width = 64;
	game->tex_height = 64;
	game->tex_so = mlx_xpm_file_to_image(game->mlx.mlx, "assets/SO.xpm",
			&game->tex_width, &game->tex_height);
	game->tex_no = mlx_xpm_file_to_image(game->mlx.mlx, "assets/NO.xpm",
			&game->tex_width, &game->tex_height);
	game->tex_ea = mlx_xpm_file_to_image(game->mlx.mlx, "assets/EA.xpm",
			&game->tex_width, &game->tex_height);
	game->tex_we = mlx_xpm_file_to_image(game->mlx.mlx, "assets/WE.xpm",
			&game->tex_width, &game->tex_height);
	game->tex_so_addr = mlx_get_data_addr(game->tex_so, &game->tex_bpp,
			&game->tex_line_len, &endian);
	game->tex_no_addr = mlx_get_data_addr(game->tex_no, &game->tex_bpp,
			&game->tex_line_len, &endian);
	game->tex_ea_addr = mlx_get_data_addr(game->tex_ea, &game->tex_bpp,
			&game->tex_line_len, &endian);
	game->tex_we_addr = mlx_get_data_addr(game->tex_we, &game->tex_bpp,
			&game->tex_line_len, &endian);
}
