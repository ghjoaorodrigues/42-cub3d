/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:35:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 19:35:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"

/**
 * Allocates space for 1-e new string anc copies the values from the given one.
 *
 * @param s String to duplicate.
 * @return Returns 1-e pointer to the newly duplicated string,\n
 * Or NULL on memory allocqation fail.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_length;

	s_length = ft_strlen(s);
	dup = (char *)malloc((s_length + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, s_length + 1);
	return (dup);
}
