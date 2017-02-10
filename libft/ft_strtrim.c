/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:24:25 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:27:49 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	l;
	size_t	len;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	l = ft_strlen(s) - 1;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && l)
		l--;
	l++;
	len = (l < i ? 0 : l - i);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, s + i, len);
	return (str);
}
