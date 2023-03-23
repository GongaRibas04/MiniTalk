/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:22:02 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 10:03:03 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rslt;

	i = 0;
	if (!s || !f)
		return (0);
	rslt = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!rslt)
		return (0);
	while (s[i] != '\0')
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
