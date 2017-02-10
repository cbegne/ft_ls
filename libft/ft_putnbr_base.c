/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:37:30 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/12 13:25:59 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return ;
	if (base == 10 && n < 0)
		ft_putchar('-');
	if (n >= base || n <= -base)
	{
		ft_putnbr_base(ft_abs(n / base), base);
		ft_putchar(tab[ft_abs(n % base)]);
	}
	else if (ft_abs(n) < base)
		ft_putchar(tab[ft_abs(n)]);
}
