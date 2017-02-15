/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:45:09 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/12 16:35:21 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*out;
	char		ch;

	out = NULL;
	ch = c;
	while (*s)
	{
		if (*s == ch)
			out = s;
		s++;
	}
	if (ch == '\0')
		return ((char*)s);
	return ((char*)out);
}
