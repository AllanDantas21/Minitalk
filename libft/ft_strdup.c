/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:55:52 by aldantas          #+#    #+#             */
/*   Updated: 2023/10/31 19:12:29 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;
	char	*s2;
	char	*pos;

	s1 = (char *)s;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	pos = s2;
	while (*s1)
	{
		*s2++ = *s1++;
	}
	*s2 = 0;
	return (pos);
}
