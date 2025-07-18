/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:46:05 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:48:53 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_error.h"
#include "jal_gnl.h"
#include "jal_string.h"
#include "read_int.h"
#include <fcntl.h>
#include <unistd.h>

static void	ft_skip_empty_lines(char **line, int *read_count, const int fd)
{
	while (line && ft_isempty(*line))
	{
		free(*line);
		*line = get_next_line(fd);
		*read_count += 1;
	}
}

int	ft_read(const char *path, t_game *game)
{
	char	*line;
	int		read_count;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Failed to open map file", E_FD_OPEN));
	read_count = 0;
	line = get_next_line(fd);
	read_count++;
	if (ft_texture(&line, &read_count, fd, game) != 0)
		return (ft_gnl_free_buffer(line, fd), close(fd), 1);
	ft_skip_empty_lines(&line, &read_count, fd);
	ft_gnl_free_buffer(line, fd);
	close(fd);
	if (ft_map(path, read_count, &game->map.matrix) != 0)
		return (1);
	return (0);
}
