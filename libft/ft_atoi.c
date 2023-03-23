/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:55:54 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/10 18:24:47 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*(str++) - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}
