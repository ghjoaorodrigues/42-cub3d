/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:51:17 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 18:51:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_conversion.h"
#include "jal_error.h"
#include "jal_gnl.h"
#include "jal_memory.h"
#include "jal_string.h"
#include "read_int.h"

int	ft_get_texture(char *line, char *txt_name, char **text_ptr)
{
	if (!ft_strncmp(line, txt_name, 3))
	{
		if (*text_ptr)
			return (ft_error("A texture is given more than once", E_DUP_INFO));
		*text_ptr = ft_strtrim(line + 3, " \n");
		if (!*text_ptr)
			return (ft_error("Memory allocation failed", E_NOMEM));
	}
	return (0);
}

int	ft_colour_helper(char **split, int *colour)
{
	int	col[3];
	int	valid;

	valid = 1;
	col[0] = ft_atoll_valid(split[0], 0, 255, &valid);
	col[1] = ft_atoll_valid(split[1], 0, 255, &valid);
	col[2] = ft_atoll_valid(split[2], 0, 255, &valid);
	if (!valid)
		return (1);
	*colour = (col[0] << 16) | (col[1] << 8) | col[2];
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

int	ft_info_full(const t_texture *info)
{
	return (info->NO && info->SO && info->EA && info->WE && info->F != -1
		&& info->C != -1);
}

int	ft_process_info(char *line, t_texture *texture) {
	if (!ft_strncmp(line, "NO ", 3))
		return (ft_get_texture(line, "NO ", &texture->NO));
	if (!ft_strncmp(line, "SO ", 3))
		return (ft_get_texture(line, "SO ", &texture->SO));
	if (!ft_strncmp(line, "EA ", 3))
		return (ft_get_texture(line, "EA ", &texture->EA));
	if (!ft_strncmp(line, "WE ", 3))
		return (ft_get_texture(line, "WE ", &texture->WE));
	if (!ft_strncmp(line, "F ", 2))
		return (ft_get_colour(line, "F ", &texture->F));
	if (!ft_strncmp(line, "C ", 2))
		return (ft_get_colour(line, "C ", &texture->C));
	if (!ft_isempty(line))
		return (ft_error("Invalid line on map file",
				E_INVALID_LINE));
	return (0);
}

int	ft_texture(char **line, int *read_count, int fd, t_texture *texture)
{
	while (*line && !ft_info_full(texture))
	{
		if (ft_process_info(*line, texture) != 0)
			return (ft_free_texture(texture), 1);
		free(*line);
		*line = get_next_line(fd);
		*read_count += 1;
	}
	return (0);
}
