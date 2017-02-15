/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:50:28 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:00:12 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_size(int value, int base)
{
	int	nb;

	nb = 0;
	if (base == 10 && value < 0)
		nb++;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		nb++;
	}
	return (nb);
}

char			*ft_itoa_base(int value, int base)
{
	char	tab[16];
	char	*out;
	int		nb;
	int		i;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	ft_strncpy(tab, "0123456789ABCDEF", base);
	nb = count_size(value, base);
	if (!(out = ft_strnew(nb)))
		return (NULL);
	nb--;
	if (base == 10 && value < 0)
		out[i++] = '-';
	while (nb >= i)
	{
		out[nb] = tab[ft_abs(value % base)];
		value = value / base;
		nb--;
	}
	return (out);
}
