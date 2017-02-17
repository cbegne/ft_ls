/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:49:20 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 16:47:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_usage(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-Ralrt1] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	ls_error(char *str, int errnum)
{
	ft_putstr_fd("ls: ", 2);
	if (str[0] != '\0')
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putchar_fd('\n', 2);
	}
	else
	{
		ft_putstr_fd("fts_open", 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putchar_fd('\n', 2);
		exit(EXIT_FAILURE);
	}
}
