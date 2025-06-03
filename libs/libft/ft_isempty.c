/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:56:46 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/05/27 23:01:08 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_isspace(const char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

int ft_isempty(const char *s)
{
    if (!s) return 1;
    while (*s)
    {
        if (!ft_isspace((unsigned char)*s))
            return 0;
        s++;
    }
    return 1;
}

