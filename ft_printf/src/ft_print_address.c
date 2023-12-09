/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:20:12 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/16 06:06:19 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_address(void *pointer)
{
	int					counter;
	char				*str;
	unsigned long long	address;

	counter = 0;
	address = (unsigned long long)pointer;
	if (!pointer)
	{
		counter = ft_print_string("(nil)");
		return (counter);
	}
	str = utoa_base(address, 16, "0123456789abcdef");
	counter += ft_print_string("0x");
	counter += ft_print_string(str);
	free(str);
	return (counter);
}
