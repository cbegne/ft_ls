/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:46:11 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/09 17:25:43 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ds;
	const unsigned char *sr;
	size_t				i;

	ds = dst;
	sr = src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == (unsigned char)c)
			return (ds + i + 1);
		i++;
	}
	return (NULL);
}
