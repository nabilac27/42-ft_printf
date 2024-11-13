/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:14:28 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/13 21:18:27 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		if (ft_printf_s("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (ft_printf_c('-') == -1)
			return (-1);
		return (ft_printf_d(-1 * n) + 1);
	}
	else if (n < 10)
	{
		if (ft_printf_c(n + '0') == -1)
			return (-1);
		return (1);
	}
	i = ft_printf_d(n / 10);
	if (i == -1 || ft_printf_c(n % 10 + '0') == -1)
		return (-1);
	return (i + 1);
}

int	ft_printf_u(unsigned int n)
{
	int	i;

	if (n < 10)
		return (ft_printf_c(n + '0'));
	else
	{
		i = ft_printf_u(n / 10);
		if (i == -1)
			return (-1);
		return (i + ft_printf_u(n % 10));
	}
}
