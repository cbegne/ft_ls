/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:08:27 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 10:34:42 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_option	opt;
	int			i;
	t_ls		*root;

	i = get_option(&opt, av);
	ac = ac - i;
	ft_sort_params(ac + 1, av + i - 1);
	form_tree(ac, av + i, &root, &opt);
	if (opt.d)
		print_files(root, &opt, 1);
	else
		print_files(root, &opt, 0);
	if (!opt.d && opt.print == 1 && root->nb_dir)
		ft_printf("\n");
	while (!opt.d && root->nb_dir)
	{
		print_dir(root, &opt, root->nb_dir, ac);
		if (ac != 1 && ac - root->nb_dir > 0 && root->nb_dir)
			ft_printf("\n");
	}
	free_nodes(&root);
	return (0);
}
