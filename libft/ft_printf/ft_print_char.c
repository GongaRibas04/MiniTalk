/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:04:15 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 15:05:48 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(va_list args)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)", 6);
		return (6);
	}
	ft_putstr(str, 1);
	return (ft_strlen(str));
}
