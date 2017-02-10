/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:08:27 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/10 16:20:31 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/**
static void print_param(t_ls *root)
{
	printf("perm %s\n", root->perm);
	printf("nlink %hu\n", root->nlink);
	printf("uid %s\n", root->uid);
	printf("gid %s\n", root->gid);
	printf("mode %hu\n", root->mode);
	printf("size %lld\n", root->size);
	printf("time %ld\n", root->time);
	printf("date %s\n", root->date);
	printf("blocks %lld\n", root->blocks);
	printf("name %s\n", root->name);
	printf("path %s\n", root->path);
	printf("min %d\n", root->min);
	printf("maj %d\n", root->maj);
}
**/
int		main(int ac, char **av)
{
	t_option	opt;
	int			i;
	t_ls		*root;

	i = get_option(&opt, av);
	ac = ac - i;
	ft_sort_params(ac + 1, av + i - 1);
	form_tree(ac, av + i, &root, &opt);
	print_files(root, &opt, 0);
	if (opt.print == 1 && root->nb_dir)
		ft_printf("\n");
	while (root->nb_dir)
	{
		print_dir(root, &opt, root->nb_dir, ac);
		if (ac != 1 && ac - root->nb_dir > 0 && root->nb_dir)
			ft_printf("\n");
	}
	return (0);
}
