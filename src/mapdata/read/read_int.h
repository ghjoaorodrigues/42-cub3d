/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:48:05 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/05 18:48:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INT_H
#define READ_INT_H

#include "../mapdata_int.h"

int	ft_get_info(char **line, int *read_count, int fd, t_data *data);
int	ft_get_map(const char *path, int read_count, char ***map);

#endif //READ_INT_H
