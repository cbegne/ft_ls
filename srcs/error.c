/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:49:20 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/26 15:11:26 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_usage(char c)
{
	ft_printf("ft_ls : illegal option -- %c\n", c);	
	ft_printf("usage: ft_ls [-larRt] [file ...]\n");
	exit(EXIT_FAILURE);
}
