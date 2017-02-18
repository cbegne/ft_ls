/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:28:02 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/16 16:17:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		number_words(char const *s, char c)
{
	int nb;

	nb = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			nb++;
			while (*s != c && *s)
				s++;
		}
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = number_words(s, c);
	if (!(tab = ft_memalloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (i < nb)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		if (!(tab[i] = ft_strndup(s, j)))
			return (NULL);
		i++;
		s = s + j;
	}
	tab[i] = 0;
	return (tab);
}
