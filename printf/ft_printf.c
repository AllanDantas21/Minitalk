/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:15:12 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/16 06:23:08 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_fmt(const char arg, va_list ap)
{
	int	count;

	count = 0;
	if (arg == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (arg == 'd' || arg == 'i')
		count += ft_print_decimal(va_arg(ap, signed int));
	else if (arg == 's')
		count += ft_print_string(va_arg(ap, char *));
	else if (arg == 'p')
		count += ft_print_address(va_arg(ap, void *));
	else if (arg == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (arg == 'x')
		count += ft_print_hexa(va_arg(ap, unsigned int));
	else if (arg == 'X')
		count += ft_print_hexa_upper(va_arg(ap, unsigned int));
	else if (arg == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			count += ft_print_fmt(fmt[i + 1], ap);
			i++;
		}
		else
			count += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
