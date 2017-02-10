/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:03:08 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:24:17 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str != NULL)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
