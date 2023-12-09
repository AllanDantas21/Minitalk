/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:16:38 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/09 08:16:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_decimal(int decimal)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_itoa(decimal);
	count += ft_print_string(str);
	free(str);
	return (count);
}
