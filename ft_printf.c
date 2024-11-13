/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:45:32 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/13 21:06:04 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		i;
	int		length;
	int		result;

	va_start(arg_ptr, str);
	i = 0;
	length = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			result = ft_printf_format(str[i], arg_ptr);
		}
		else
			result = write(1, &str[i], 1);
		if (result == -1)
			return (-1);
		length = length + result;
		i++;
	}
	va_end(arg_ptr);
	return (length);
}

int	ft_printf_format(char specifier, va_list arg_ptr)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length = ft_printf_c(va_arg(arg_ptr, int));
	else if (specifier == 's')
		length = ft_printf_s(va_arg(arg_ptr, char *));
	else if (specifier == 'p')
		length = ft_printf_p(va_arg(arg_ptr, void *));
	else if (specifier == 'd' || specifier == 'i')
		length = ft_printf_d(va_arg(arg_ptr, int));
	else if (specifier == 'x' || specifier == 'X')
		length = ft_printf_x(va_arg(arg_ptr, unsigned int), specifier);
	else if (specifier == 'u')
		length = ft_printf_u(va_arg(arg_ptr, unsigned int));
	else if (specifier == '%')
		length = ft_printf_c('%');
	if (length == -1)
		return (-1);
	return (length);
}
