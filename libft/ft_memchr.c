/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:40:49 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 09:33:09 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_aux;
	size_t			i;

	str_aux = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (str_aux[i] == (unsigned char)c)
			return (str_aux + i);
		i++;
	}
	return (NULL);
}
