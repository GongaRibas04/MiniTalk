/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:17:30 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 15:17:33 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int len)
{
	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_ptr(unsigned long long int p)
{
	char	*base;

	base = "0123456789abcdef";
	if (p >= 16)
	{
		ft_ptr(p / 16);
		ft_ptr(p % 16);
	}
	else
		write(1, &base[p], 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
