/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:48:04 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/15 12:25:42 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*tab;
	size_t	i;

	i = 0;
	while (src[i] && i < n)
		i++;
	n = i;
	if (!(tab = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
