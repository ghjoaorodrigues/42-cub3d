/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_free_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:59:06 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 18:59:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_gnl.h"

void	ft_gnl_free_buffer(char *line, const int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
