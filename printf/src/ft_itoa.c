/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:49:04 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/16 05:13:23 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	size_num(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		len++;
	else if (nbr == (-2147483648))
	{
		len = 11;
	}
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			len++;
		}
		while (nbr > 0)
		{
			len++;
			nbr /= 10;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	len = size_num(n);
	num = n;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
