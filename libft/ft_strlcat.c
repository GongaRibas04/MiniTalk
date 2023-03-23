/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:18 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 09:53:19 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	ret;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (*dest && i < n)
	{
		++dest;
		++i;
	}
	ret = (size_t)ft_strlcpy(dest, src, n - i);
	return (ret + i);
}
