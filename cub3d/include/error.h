/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/06/04 16:06:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include "jal_error.h"

enum e_error {
	E_ARGS = 1,
	E_PATH_EMPTY,
	E_PATH_EXT,
	E_DUP_INFO,
	E_DUP_COLOUR,
	E_COLOUR_FORMAT,
	E_INVALID_LINE,
	E_NOEMPTY_LINE,
	E_MISS_DATA,
	E_INVALID_CHAR,
	E_PLAYER_DUP,
	E_NO_PLAYER,
	E_MAP_SURRONDED,
	E_MLX_INIT,
	E_MLX_XPM
};

#endif //ERROR_H
