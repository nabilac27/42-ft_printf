/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:45:32 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/10 19:50:27 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		i;
	int		length;

	va_start(arg_ptr, str);
	i = 0;
	length = 0;

	if (!str)
		return(-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			length = length + ft_printf_format(str[i], arg_ptr);
		}
		else
			length = length + write(1, &str[i], 1);
		i++;
	}
	va_end(arg_ptr);
	return (length);
}

int	ft_printf_format(char specifier, va_list arg_ptr)
{
	int length;

	length = 0;
	if (specifier == 'c')
		length = length + ft_printf_c(va_arg(arg_ptr, int));
	else if (specifier == 's')
		length = length + ft_printf_s(va_arg(arg_ptr, char *));
	else if (specifier == 'p')
		length = length + ft_printf_p(va_arg(arg_ptr, uintptr_t));
	else if (specifier == 'd' || specifier == 'i')
		length = length + ft_printf_d(va_arg(arg_ptr, int));
	else if (specifier == 'x' || specifier == 'X')
		length = length + ft_printf_x(va_arg(arg_ptr, unsigned int), specifier);
	else if (specifier == 'u')
		length = length + ft_printf_u(va_arg(arg_ptr, unsigned int));
	else if (specifier == '%')
		length = length + ft_printf_c('%');
	else
		length = -1;
	return (length);
}