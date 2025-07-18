/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:59:45 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/07 15:59:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_int.h"
#include "jal_error.h"
#include "jal_string.h"

static void	ft_get_dimensions(t_map *map)
{
	int	height;
	int	width;
	int	len;

	height = 0;
	width = 0;
	while (map->matrix[height])
	{
		len = ft_strlen(map->matrix[height]);
		if (len > width)
			width = len;
		height++;
	}
	map->height = height;
	map->width = width;
}

static int	ft_complete_line(char **line, int width)
{
	char	*new;
	int		i;

	new = malloc((width + 1 * sizeof(char)));
	if (!new)
		return (ft_error("Memory allocation failed", E_NOMEM));
	i = -1;
	while ((*line)[++i])
		new[i] = (*line)[i];
	while (i < width)
		new[i++] = ' ';
	new[i] = '\0';
	free(*line);
	*line = new;
	return (0);
}

int	ft_format_map(t_map *map)
{
	int	i;

	ft_get_dimensions(map);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->matrix[i]) < map->width)
			if (ft_complete_line(&map->matrix[i], map->width) != 0)
				return (1);
		i++;
	}
	return (0);
}
