/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:12:09 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 18:51:49 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*str;

	str = ft_strnew(size);
	ft_memset(str, c, size);
	return (str);
}
