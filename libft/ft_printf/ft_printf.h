/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:06:48 by gobarbos          #+#    #+#             */
/*   Updated: 2022/12/12 15:16:07 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

// utils:
void			ft_putstr(char *s, int len);
size_t			ft_strlen(const char *str);
void			ft_ptr(unsigned long long int p);
void			ft_putchar_fd(char c, int fd);
// len:
int				ptr_len(unsigned long long int p);
int				len_int(int n);
int				len_unsint(unsigned int n);
int				len_hex(unsigned int n);
// printf:
int				ft_printf(const char *str, ...);
int				ft_check(char *str, va_list args);
int				ft_printchr(va_list args);
int				ft_printstr(va_list args);
int				ft_printptr(va_list args);
int				ft_printdec(va_list args);
unsigned int	ft_printuns(va_list args);
int				ft_printhex(va_list args, char format);
void			ft_hex(unsigned int n, char format);

#endif
