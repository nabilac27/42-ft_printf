/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:38:38 by nchairun          #+#    #+#             */
/*   Updated: 2024/11/10 18:48:05 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_format(char specifier, va_list arg_ptr);

int	ft_printf_c(int c);
int	ft_printf_s(char *s);

int	ft_printf_p(uintptr_t n);
int	ft_printf_hex(uintptr_t n);

int	ft_printf_d(int n);
int	ft_printf_x(unsigned int n, char specifier);

int	ft_printf_hex_upper(uintptr_t n);
int	ft_printf_u(unsigned int n);

#endif