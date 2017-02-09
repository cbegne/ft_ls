/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:23:43 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/07 15:04:15 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_option(char c)
{
	if (c == 'l' || c == 'a' || c == 'r' || c == 'R' || c == 't' || c == '1')
		return (1);
	return (0);
}

static void	fill_opt(t_option *opt, char *av)	
{
	int i;
	
	i = 1;
	while (av[i])
	{	
		if (!(is_option(av[i])))
			error_usage(av[i]);
		opt->l = (av[i] == 'l' ? 1 : opt->l);
		opt->a = (av[i] == 'a' ? 1 : opt->a);
		opt->r = (av[i] == 'r' ? 1 : opt->r);
		opt->upper_r = (av[i] == 'R' ? 1 : opt->upper_r);
		opt->t = (av[i] == 't' ? 1 : opt->t);
		opt->l = (av[i] == '1' ? 0 : opt->l);
		i++;
	}
}

int		get_option(t_option *opt, char **av)
{
	int	i;

	i = 1;
	ft_bzero(opt, sizeof(t_option));
	while (av[i] && av[i][0] == '-')
	{
		if (av[i][1] == 0)
			break ;
		if (av[i][1] == '-')
		{
			i++;
			break ;
		}
		fill_opt(opt, av[i]);
		i++;
	}
	return (i);
}
