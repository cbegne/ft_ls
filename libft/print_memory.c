/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:47:18 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/12 18:44:22 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_hex(unsigned char c)
{
	char	*tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[c / 16]);
	ft_putchar(tab[c % 16]);
}

void	print_hex(unsigned char *s, size_t size, size_t start)
{
	int i;

	i = 0;
	while (start + i < size && i < 16)
	{
		putnbr_hex(s[start + i]);
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
	}
	while (i < 16)
	{
		ft_putstr("  ");
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
	}
}

void	print_char(unsigned char *s, size_t size, size_t start)
{
	int i;

	i = 0;
	while (start + i < size && i < 16)
	{
		if (s[start + i] < 32 || s[start + i] > 126)
			ft_putchar('.');
		else
			ft_putchar(s[start + i]);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_hex((unsigned char*)addr, size, i);
		print_char((unsigned char*)addr, size, i);
		ft_putchar('\n');
		i = i + 16;
	}
}
