/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:57:31 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 15:03:38 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(va_list args)
{
	long long int	p;
	int				len;

	p = va_arg(args, long long int);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x", 1);
	len = ptr_len(p);
	ft_ptr(p);
	return (len + 2);
}

int	ft_printdec(va_list args)
{
	int	n;
	int	len;

	n = va_arg(args, int);
	len = len_int(n);
	return (len);
}

unsigned int	ft_printuns(va_list args)
{
	unsigned int	n;
	int				len;

	n = va_arg(args, unsigned int);
	len = len_unsint(n);
	return (len);
}

void	ft_hex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_hex(n / 16, format);
		ft_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(va_list args, char format)
{
	unsigned int	n;
	int				len;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		ft_hex(n, format);
	}
	len = len_hex(n);
	return (len);
}
