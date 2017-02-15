/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:01:09 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/05 16:47:46 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tab;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	tab = (char*)malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
