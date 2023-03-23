/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:16 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 10:48:00 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	int		c;

	i = start;
	c = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s) && len-- > 0)
		str[c++] = s[i++];
	str[c] = '\0';
	return (str);
}
