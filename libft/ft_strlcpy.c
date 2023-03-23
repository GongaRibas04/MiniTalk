/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:24:18 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 09:55:01 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*src && (i + 1) < n)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < n)
		*dest = 0;
	while (*src++)
		++i;
	return ((size_t)i);
}
