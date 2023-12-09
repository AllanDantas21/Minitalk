/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:19:58 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/09 08:19:59 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_string(const char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		str = "(null)";
	while (str[counter] != '\0')
		write(1, &str[counter++], 1);
	return (counter);
}
