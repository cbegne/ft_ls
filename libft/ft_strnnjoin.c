/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:58:38 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 19:46:18 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnnjoin(char const *s1, char const *s2, size_t n1, size_t n2)
{
	char	*str;

	str = ft_strnew(n1 + n2);
	if (str != NULL)
	{
		ft_memcpy(str, s1, n1);
		ft_memcpy(str + n1, s2, n2);
	}
	return (str);
}
