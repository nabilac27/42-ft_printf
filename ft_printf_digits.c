/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:14:28 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/08 00:16:36 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_printf_s("-2147483648"));
	else if (n < 0)
	{
		ft_printf_c('-');
		return (ft_printf_d(-1 * n) + 1);
	}
	else if (n < 10)
		return (ft_printf_c(n + '0'));
	else
	{
		i = ft_printf_d(n / 10);
		return (i + ft_printf_d(n % 10));
	}
	return (i);
}

int	ft_printf_u(unsigned int n)
{
	int	i;

	if (n < 10)
		return (ft_printf_c(n + '0'));
	else
	{
		i = ft_printf_u(n / 10);
		return (i + ft_printf_u(n % 10));
	}
	return (i);
}
