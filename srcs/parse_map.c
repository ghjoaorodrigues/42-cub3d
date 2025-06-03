/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:44 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/05/27 23:20:41 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	cleanup_error(t_game *game, int fd, char *line)
{
	if (game->NO)
		free(game->NO);
	if (game->WE)
		free(game->WE);
	if (game->SO)
		free(game->SO);
	if (game->EA)
		free(game->EA);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (-1);
}
int	parse_rgb(char *str)
{
	char	**split;
	int		color;
	int		r;
	int		g;
	int		b;

	split = ft_split(str, ',');
	if (!split || ft_isempty(split[0]) || ft_isempty(split[1]) || ft_isempty(split[2]) || split[3])
		return (free_split(split),ft_printf("Error with split on parse_rgb function or missing color\n"), -1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_split(split), ft_printf("Error values must be between 0 and 255\n"), -1);
	color = (r << 16) | (g << 8) | b;
	free_split(split);
	return (color);
}

int	parse_textures(char *filename, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("error opening file map\n"), -1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			game->NO = ft_strtrim(line + 3, "\n");
		else if (ft_strncmp(line, "WE ", 3) == 0)
			game->WE = ft_strtrim(line + 3, "\n");
		else if (ft_strncmp(line, "SO ", 3) == 0)
			game->SO = ft_strtrim(line + 3, "\n");
		else if (ft_strncmp(line, "EA ", 3) == 0)
			game->EA = ft_strtrim(line + 3, "\n");
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			game->floor_color = parse_rgb(line + 2);
			if (game->floor_color == -1)
				return (cleanup_error(game, fd, line));
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			game->ceiling_color = parse_rgb(line + 2);
			if (game->ceiling_color == -1)
				return (cleanup_error(game, fd, line));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
char	**dup_map(char **original, t_game *game)
{
	int		height;
	char	**copy;
	int		i;
	int		j;

	height = 0;
	i = 0;
	while (original[i] && !is_mapline(original[i]))
		i++;
	if (original[i])
		i++;
	while (original[i + height])
		height++;
	game->map_height = height;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (j < height)
	{
		copy[j] = ft_strdup(original[i + j]);
		if (!copy[j])
		{
			while (--j >= 0)
				free(copy[j]);
			free(copy);
			return (NULL);
		}
		j++;
	}
	copy[j] = NULL;
	return (copy);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	load_map(char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * (count_lines(filename) + 1));
	if (!game->map)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("error opening file map\n"), -1);
	i = -1;
	while ((line = get_next_line(fd)))
	{
		game->map[++i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
			return (close(fd), -1);
	}
	return (game->map[++i] = NULL, close(fd), 0);
}
