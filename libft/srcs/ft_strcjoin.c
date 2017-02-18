/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:46:59 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/17 15:00:47 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char const *s2, char c)
{
	char	*str;
	int		len1;

	len1 = ft_strlen(s1);
	str = ft_strnew(len1 + ft_strlen(s2) + 1);
	if (str != NULL)
	{
		ft_strcpy(str, s1);
		*(str + len1) = c;
		ft_strcat(str, s2);
	}
	return (str);
}
