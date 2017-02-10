/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:27:22 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:09:35 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		ft_putchar_fd(ft_abs(n % 10) + '0', fd);
	}
	else if (n <= 9 || n >= -9)
		ft_putchar_fd(ft_abs(n) + '0', fd);
}
