/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:47:07 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/18 15:24:07 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s)
	{
		if (*s != c)
		{
			r++;
			while (*s && *s != c)
			s++;
		}
		else
			s++;
	}
	return (r);
}

char const	*save_word(char const *s, char c, size_t i, char **rslt)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	rslt[i++] = ft_substr(s - len, 0, len);
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	rslt = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!rslt)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			s = save_word(s, c, i, rslt);
			i++;
		}
		else
			s++;
	}
	rslt[i] = 0;
	return (rslt);
}
