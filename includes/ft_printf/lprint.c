/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:06:19 by vsoares-          #+#    #+#             */
/*   Updated: 2024/12/02 16:58:59 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lprint_chr(int c)
{
	return (write(1, &c, 1));
}

int	lprint_str(char *str)
{
	if (!str)
		return (lprint_str("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	lprint_dig(long n, char *base)
{
	int	base_size;

	base_size = ft_strlen(base);
	if (n < 0)
		return (lprint_chr('-') + lprint_dig(-n, base));
	else if (n < base_size)
		return (lprint_chr(base[n]));
	else
		return (lprint_dig(n / base_size, base)
			+ lprint_dig(n % base_size, base));
}

int	lprint_hex(unsigned long n, char *base)
{
	unsigned long	base_size;

	base_size = ft_strlen(base);
	if (n < base_size)
		return (lprint_chr(base[n]));
	else
		return (lprint_hex(n / base_size, base)
			+ lprint_hex(n % base_size, base));
}

int	lprint_ptr(void *ptr)
{
	int				counter;
	unsigned long	ptr_value;

	if (!ptr)
		return (lprint_str("(nil)"));
	ptr_value = (unsigned long)ptr;
	counter = lprint_str("0x");
	counter += lprint_hex(ptr_value, HEXA_LOW);
	return (counter);
}
