/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:17:09 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/14 16:20:41 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
		return (NULL);
	if (s1 && !s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char *) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[i] = '\0';
	return (str);
}
