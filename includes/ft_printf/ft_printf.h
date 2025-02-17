/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:22:53 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/17 19:05:47 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define DEBUG_MODE 0

# ifndef DECIMAL
#  define DECIMAL "0123456789"
# endif
# ifndef HEXA_UP
#  define HEXA_UP "0123456789ABCDEF"
# endif
# ifndef HEXA_LOW
#  define HEXA_LOW "0123456789abcdef"
# endif

# ifndef NEGATIVE_HEX
#  define NEGATIVE_HEX 0
# endif
# ifndef DIG_OVERFLOW
#  define DIG_OVERFLOW 1
# endif

int	ft_strlen(char *str);

int	lprint_chr(int c);
int	lprint_str(char *str);
int	lprint_ptr(void *ptr);
int	lprint_dig(long n, char *base);
int	lprint_hex(unsigned long n, char *base);

int	debug(const char *str, ...);
int	ft_printf(const char *str, ...);

#endif