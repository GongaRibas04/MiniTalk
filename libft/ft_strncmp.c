/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:38:14 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 09:58:03 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			c;
	unsigned int	dif;

	c = 0;
	dif = 0;
	while ((c < n) && !dif && (str1[c] != 0) && (str2[c] != 0))
	{
		dif = (unsigned char)str1[c] - (unsigned char)str2[c];
		c++;
	}
	if (c < n && !dif && (str1[c] == 0 || str2[c] == 0))
		dif = (unsigned char)str1[c] - (unsigned char)str2[c];
	return (dif);
}
