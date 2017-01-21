/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:08:27 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/21 17:37:24 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_option	opt;
	int			i;
	t_ls		*root;

	i = 1;
//	if (av[i][0] != '-')
//		error "No such file or directory"
	while (av[i] && av[i][0] == '-')
		get_option(&opt, av[i++]);
//	if (opt.l == 0)
//		error usage
	ac = ac - i;
	ft_sort_params(ac + 1, av + i - 1);
//	printf("ac %d av %s\n", ac, av[i]);
	form_tree(ac, av + i, &root, &opt);
	printf("perm %s\n", root->perm);
	printf("nlink %hu\n", root->nlink);
	printf("uid %s\n", root->uid);
	printf("gid %s\n", root->gid);
//	printf("mode %hu\n", root->mode);
//	printf("rdev %d\n", root->rdev);
	printf("size %lld\n", root->size);
//	printf("time %ld\n", root->time);
	printf("date %s\n", root->date);
//	printf("blocks %lld\n", root->blocks);
	printf("name %s\n", root->name);
	printf("path %s\n", root->path);
	
//	apply opt
//	print
}
