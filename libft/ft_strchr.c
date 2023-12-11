/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:59:20 by aldantas          #+#    #+#             */
/*   Updated: 2023/10/30 14:35:02 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*a;

	if (c > 127)
		c %= 256;
	a = (unsigned char *) s;
	while (*a)
	{
		if (*a == (unsigned char)c)
			return ((char *)(a));
		a++;
	}
	if (*a == c)
		return ((char *)(a));
	return (NULL);
}
