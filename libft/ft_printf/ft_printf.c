/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:55:44 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 14:57:08 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char *str, va_list args)
{
	char	format;
	int		len;

	len = -2;
	format = *str;
	if (format == 'c')
		len += ft_printchr(args);
	else if (format == 's')
		len += ft_printstr(args);
	else if (format == 'p')
		len += ft_printptr(args);
	else if (format == 'd')
		len += ft_printdec(args);
	else if (format == 'i')
		len += ft_printdec(args);
	else if (format == 'u')
		len += ft_printuns(args);
	else if (format == 'x' || format == 'X')
		len += ft_printhex(args, format);
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, str);
	len = ft_strlen(str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			len += ft_check(&((char *)str)[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (len);
}
