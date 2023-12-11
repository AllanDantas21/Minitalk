/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:38:13 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/10 15:15:23 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_w(char const *s, char c)
{
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

static void	alloc_w(char const *s, char c, char **arr)
{
	size_t	letters;
	int		i;

	i = 0;
	if (s)
	{
		letters = 0;
		while (*s)
		{
			while (*s == c)
				s++;
			while (*s != c && *s)
			{
				letters++;
				s++;
			}
			arr[i] = ft_substr(s - letters, 0, letters);
			i++;
			letters = 0;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_w(s, c);
	arr = (char **) malloc (sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	alloc_w(s, c, arr);
	arr[words] = 0;
	return (arr);
}
