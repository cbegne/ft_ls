/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:11:44 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/10 16:22:18 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		do_not_open(t_ls *list)
{
	if (!ft_strcmp(list->name, ".") || !ft_strcmp(list->name, ".."))
		return (1);
	return (0);
}

void	print_dir(t_ls *root, t_option *opt, int nb_dir, int ac)
{
	t_ls	*new_root;
	char	*path;

	if (nb_dir == 0)
		return ;
	opt->done = 0;
	if (!opt->r)
		find_dir(root, &path);
	else
		find_dir_reverse(root, &path, opt);
	if (ac > 1)
		ft_printf("%s:\n", path);
	new_root = (t_ls*)ft_memalloc(sizeof(t_ls));
	form_dir_tree(path, new_root, opt);
	if (new_root->name)
		print_files(new_root, opt, root->nb_dir);
	root->nb_dir--;
	while (opt->upper_r && new_root->nb_dir)
	{
		ft_printf("\n");
		print_dir(new_root, opt, new_root->nb_dir, 2);
	}
	free(new_root);
}
