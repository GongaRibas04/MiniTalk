/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:47:42 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 09:56:56 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (len == 0 && (!str1 || !str2))
		return (0);
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[h] != '\0')
	{
		n = 0;
		while (str1[h + n] == str2[n] && (h + n) < len)
		{
			if (str1[h + n] == '\0' && str2[n] == '\0')
				return ((char *)&str1[h]);
			n++;
		}
		if (str2[n] == '\0')
			return ((char *)str1 + h);
		h++;
	}
	return (0);
}
