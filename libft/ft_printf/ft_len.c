/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:50:25 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 14:54:06 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long int p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	len_int(int n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	len++;
	}
	if (n >= 10)
		len += len_int(n / 10);
	write(1, &base[n % 10], 1);
	return (len + 1);
}

int	len_unsint(unsigned int n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n >= 10)
		len += len_unsint(n / 10);
	write(1, &base[n % 10], 1);
	return (len + 1);
}

int	len_hex(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
