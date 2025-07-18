/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:51:17 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:47:36 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_conversion.h"
#include "jal_error.h"
#include "jal_gnl.h"
#include "jal_memory.h"
#include "jal_string.h"
#include "mlx.h"
#include "read_int.h"

int	ft_get_texture(char *line, char *txt_name, void **img_ptr, void *mlx)
{
	char	*path;
	int		size;

	if (!ft_strncmp(line, txt_name, 3))
	{
		if (*img_ptr)
			return (ft_error("A texture is given more than once", E_DUP_INFO));
		path = ft_strtrim(line + 3, " \n");
		if (!path)
			return (ft_error("Memory allocation failed", E_NOMEM));
		size = TEXTURE_SIZE;
		*img_ptr = mlx_xpm_file_to_image(mlx, path, &size, &size);
		free(path);
		if (!*img_ptr)
			return (ft_error("Mlx failed to get texture", E_MLX_XPM));
	}
	return (0);
}

int	ft_get_colour(char *line, char *txt_name, int *colour)
{
	char	**split;
	char	*trimmed;

	if (!ft_strncmp(line, txt_name, 2))
	{
		if (*colour != -1)
			return (ft_error("A colour is given more than once", E_DUP_COLOUR));
		trimmed = ft_strtrim(line + 2, "\n");
		if (!trimmed)
			return (ft_error("Memory allocation failed", E_NOMEM));
		split = ft_split(trimmed, ',');
		free(trimmed);
		if (!split)
			return (ft_error("Memory allocation failed", E_NOMEM));
		if (!split[0] || ft_isempty(split[0]) || !split[1]
			|| ft_isempty(split[1]) || !split[2] || ft_isempty(split[2])
			|| split[3] != NULL || ft_colour_helper(split, colour) != 0)
		{
			ft_free_matrix((void **)split);
			return (ft_error("Invalid colour format", E_COLOUR_FORMAT));
		}
		ft_free_matrix((void **)split);
	}
	return (0);
}

int	ft_info_full(const t_map *map)
{
	return (map->n_texture && map->e_texture && map->s_texture && map->w_texture
		&& map->f_colour != -1 && map->c_colour != -1);
}

int	ft_process_info(char *line, t_game *game)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (ft_get_texture(line, "NO ", &game->map.n_texture, game->mlx));
	if (!ft_strncmp(line, "EA ", 3))
		return (ft_get_texture(line, "EA ", &game->map.e_texture, game->mlx));
	if (!ft_strncmp(line, "SO ", 3))
		return (ft_get_texture(line, "SO ", &game->map.s_texture, game->mlx));
	if (!ft_strncmp(line, "WE ", 3))
		return (ft_get_texture(line, "WE ", &game->map.w_texture, game->mlx));
	if (!ft_strncmp(line, "F ", 2))
		return (ft_get_colour(line, "F ", &game->map.f_colour));
	if (!ft_strncmp(line, "C ", 2))
		return (ft_get_colour(line, "C ", &game->map.c_colour));
	if (!ft_isempty(line))
		return (ft_error("Invalid line on map file", E_INVALID_LINE));
	return (0);
}

int	ft_texture(char **line, int *read_count, int fd, t_game *game)
{
	while (*line && !ft_info_full(&game->map))
	{
		if (ft_process_info(*line, game) != 0)
			return (*ft_exit_code());
		free(*line);
		*line = get_next_line(fd);
		*read_count += 1;
	}
	if (!ft_info_full(&game->map))
		return (ft_error("Missing map data", E_MISS_DATA));
	return (0);
}
