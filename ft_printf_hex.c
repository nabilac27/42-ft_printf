/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:16:11 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/08 00:26:10 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(uintptr_t n)
{
	int	i;

	i = ft_printf_s("0x");
	if (n == 0)
		i += ft_printf_c('0');
	else
		i += ft_printf_hex(n);
	return (i);
}

int	ft_printf_hex(uintptr_t n)
{
	int		i;
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	if (n < 16)
		return (ft_printf_c(hex_digit[n]));
	else
	{
		i = ft_printf_hex(n / 16);
		return (i + ft_printf_hex(n % 16));
	}
	return (i);
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

int	ft_printf_hex_upper(uintptr_t n)
{
	int		i;
	char	*hex_digit_upper;

	hex_digit_upper = "0123456789ABCDEF";
	if (n < 16)
		return (ft_printf_c(hex_digit_upper[n]));
	else
	{
		i = ft_printf_hex_upper(n / 16);
		return (i + ft_printf_hex_upper(n % 16));
	}
	return (i);
}
