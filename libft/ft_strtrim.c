/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:09:59 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/15 10:34:04 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		posi;
	int		posf;
	int		i;
	char	*rslt;

	i = 0;
	posi = 0;
	if (!s1)
		return (NULL);
	posf = ft_strlen(s1);
	while (s1[posi] && check_set(s1[posi], set))
		posi++;
	while (posf > posi && check_set(s1[posf - 1], set))
		posf--;
	rslt = (char *) malloc(sizeof(char) * (posf - posi + 1));
	if (!rslt)
		return (0);
	while (posi < posf)
		rslt[i++] = s1[posi++];
	rslt[i] = '\0';
	return (rslt);
}
