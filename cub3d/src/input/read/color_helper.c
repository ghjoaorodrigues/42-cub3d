/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:21:30 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/18 14:47:11 by fsilva-p         ###   ########.fr       */
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
