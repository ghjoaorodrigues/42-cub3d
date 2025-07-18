/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:48:05 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/18 14:26:06 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INT_H
# define READ_INT_H

#include "../input_int.h"

int	ft_texture(char **line, int *read_count, int fd, t_game *game);
int	ft_map(const char *path, int read_count, char ***map);
int	ft_colour_helper(char **split, int *colour);

#endif // READ_INT_H
