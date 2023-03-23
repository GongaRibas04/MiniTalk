/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:16:00 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/18 15:05:42 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	neg(char *rslt, int n, int len)
{
	if (n < 0)
		rslt[0] = '-';
	if (n == -2147483647 - 1)
	{
		rslt[len - 1] = '8';
		return (-214748364);
	}
	return (-n);
}

char	*ft_itoa(int n)
{
	char	*rslt;
	int		len;

	len = ft_len(n);
	rslt = malloc(sizeof(char) * (len + 1));
	if (!rslt)
		return (0);
	rslt[len] = '\0';
	if (n < 0)
	{
		n = neg(rslt, n, len);
		if (n == -214748364)
			len--;
	}
	if (n == 0)
		rslt[0] = 48;
	while (n != 0)
	{
		len--;
		if (n < 0)
			n = n * -1;
		rslt[len] = n % 10 + 48;
		n /= 10;
	}
	return (rslt);
}
