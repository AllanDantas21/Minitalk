/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:00:13 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/01 18:58:20 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_find(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (ft_find(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len != 0)
	{
		if (ft_find(s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (char *)s1, len + 1);
	return (s2);
}
