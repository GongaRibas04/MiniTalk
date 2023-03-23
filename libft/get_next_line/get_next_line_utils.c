/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:55:47 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/28 13:55:48 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
