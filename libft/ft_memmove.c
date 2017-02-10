/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:09:08 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/14 11:36:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	const char	*sr;

	sr = src;
	ds = dst;
	if (dst < src || len == 0)
		return (ft_memcpy(dst, src, len));
	if (src < dst)
	{
		while (len)
		{
			ds[len - 1] = sr[len - 1];
			len--;
		}
	}
	return (dst);
}
