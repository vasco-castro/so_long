/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:34:36 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/17 18:56:43 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	printer(char format, va_list ap)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter = lprint_chr(va_arg(ap, int));
	else if (format == 's')
		counter = lprint_str(va_arg(ap, char *));
	else if (format == 'p')
		counter = lprint_ptr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		counter = lprint_dig((long)va_arg(ap, int), DECIMAL);
	else if (format == 'u')
		counter = lprint_dig(va_arg(ap, unsigned int), DECIMAL);
	else if (format == 'x')
		counter = lprint_hex((long)va_arg(ap, unsigned int), HEXA_LOW);
	else if (format == 'X')
		counter = lprint_hex((long)va_arg(ap, unsigned int), HEXA_UP);
	else if (format == '%')
		counter = lprint_chr(format);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	counter = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			counter += printer(str[++i], ap);
		else
			counter += lprint_chr(str[i]);
		i++;
	}
	va_end(ap);
	return (counter);
}

int	debug(const char *str, ...)
{
	va_list	args;

	if (DEBUG_MODE == 1)
	{
		va_start(args, str);
		ft_printf(str, args);
		va_end(args);
	}
	return (EXIT_SUCCESS);
}
