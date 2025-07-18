/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:47:38 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:58:46 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "jal_gnl.h"
#include "jal_memory.h"
#include "jal_string.h"
#include "read_int.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_skip_info(char **line, int fd, int read_count)
{
	while (*line && read_count-- > 0)
	{
		free(*line);
		*line = get_next_line(fd);
	}
}

int	ft_rest_is_empty(char **line, int fd)
{
	while (*line)
	{
		if (!ft_isempty(*line))
			return (0);
		free(*line);
		*line = get_next_line(fd);
	}
	return (1);
}

int	ft_count_map_lines(const char *path, int read_count)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Failed to open map file", E_FD_OPEN));
	line = get_next_line(fd);
	read_count--;
	ft_skip_info(&line, fd, read_count);
	count = 0;
	while (line && !ft_isempty(line))
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	ft_gnl_free_buffer(line, fd);
	close(fd);
	return (count);
}

int	ft_fill_map(int fd, char **line, char ***map)
{
	int		i;

	i = 0;
	while (*line && !ft_isempty(*line))
	{
		(*map)[i] = ft_strtrim(*line, "\n");
		free(*line);
		if (!(*map)[i++])
			return (ft_free_partial_matrix((void **)*map, i - 1),
				ft_error("Memory allocation failed", E_NOMEM));
		*line = get_next_line(fd);
	}
	(*map)[i] = NULL;
	return (0);
}

int	ft_map(const char *path, int read_count, char ***map)
{
	int		fd;
	char	*line;

	*map = malloc((ft_count_map_lines(path, read_count) + 1) * sizeof(char *));
	if (!*map)
		return (ft_error("Memory allocation failed", E_NOMEM));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Failed to open map file", E_FD_OPEN));
	line = get_next_line(fd);
	read_count--;
	ft_skip_info(&line, fd, read_count);
	if (ft_fill_map(fd, &line, map) != 0)
		return (ft_gnl_free_buffer(line, fd), close(fd), *ft_exit_code());
	if (!ft_rest_is_empty(&line, fd))
		return (ft_free_matrix((void **)*map), ft_gnl_free_buffer(line, fd),
			close(fd), ft_error("None empty lines found after map",
				E_NOEMPTY_LINE));
	close(fd);
	return (0);
}
