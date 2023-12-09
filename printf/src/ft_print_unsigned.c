/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:18:00 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/09 08:18:14 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		counter;

	counter = 0;
	str = utoa_base(n, 10, "0123456789");
	counter = ft_print_string(str);
	free(str);
	return (counter);
}
