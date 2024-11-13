/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:16:11 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/13 22:49:44 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *ptr)
{
	int	length;
	int	hex_length;

	length = 0;
	if (ptr == NULL)
	{
		length = ft_printf_s("0x0");
		if (length == -1)
			return (-1);
		return (length);
	}
	else
	{
		length = ft_printf_s("0x");
		if (length == -1)
			return (-1);
		hex_length = ft_printf_hex((unsigned long)ptr);
		if (hex_length == -1)
			return (-1);
		return (length + hex_length);
	}
}

int	ft_printf_hex(unsigned long n)
{
	int		length;
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	if (n < 16)
		return (write(1, &(hex_digit[n]), 1));
	else
	{
		length = ft_printf_hex(n / 16);
		if (length == -1)
			return (-1);
		return (length + ft_printf_hex(n % 16));
	}
}

int	ft_printf_x(unsigned int n, char specifier)
{
	int	i;

	if (specifier == 'x')
		i = ft_printf_hex(n);
	else
		i = ft_printf_hex_upper(n);
	return (i);
}

int	ft_printf_hex_upper(unsigned long n)
{
	int		i;
	char	*hex_digit_upper;

	hex_digit_upper = "0123456789ABCDEF";
	if (n < 16)
		return (write(1, &hex_digit_upper[n], 1));
	else
	{
		i = ft_printf_hex_upper(n / 16);
		if (i == -1)
			return (-1);
		return (i + ft_printf_hex_upper(n % 16));
	}
}
