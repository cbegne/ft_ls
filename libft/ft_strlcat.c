/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:54:42 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/12 15:54:15 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	dlen = i;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dlen + ft_strlen(src));
}
