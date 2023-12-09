/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:19:47 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/09 08:19:51 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa(unsigned int n)
{
	int		counter;
	char	*str;

	counter = 0;
	str = utoa_base(n, 16, "0123456789abcdef");
	counter += ft_print_string(str);
	free(str);
	return (counter);
}

int	ft_print_hexa_upper(unsigned int n)
{
	int		counter;
	char	*str;

	counter = 0;
	str = utoa_base(n, 16, "0123456789ABCDEF");
	counter += ft_print_string(str);
	free(str);
	return (counter);
}
