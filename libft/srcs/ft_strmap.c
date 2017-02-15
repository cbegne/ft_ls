/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:21:51 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:20:49 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
