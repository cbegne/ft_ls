/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:43:10 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:24:49 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + n);
	if (str != NULL)
	{
		ft_strcpy(str, s1);
		ft_strncat(str, s2, n);
	}
	return (str);
}
