/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:40:59 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/15 11:00:22 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && j + i < n)
		{
			j++;
			if (little[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (0);
}
