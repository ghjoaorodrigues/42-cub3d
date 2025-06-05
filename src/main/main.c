/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:50:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/06/03 16:19:26 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapdata.h"
#include "error.h"
#include "test.h"

int	main(int argc, char **argv)
{
	t_mapdata	mapdata;

	if (argc != 2)
		return (ft_error("Usage: ./cub3D <map_path>", E_ARGS));
	if (ft_mapdata(argv[1], &mapdata) != 0)
		return (*ft_exit_code());
	test_print_map_data(&mapdata);
	ft_free_mapdata(&mapdata);
	return (0);
}
