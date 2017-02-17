/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:11:44 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 18:19:23 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	find_dir(t_ls *root, char **path, t_option *opt)
{
	if (!root)
		return ;
	if (root->right)
		find_dir(root->right, path, opt);
	if (root->perm[0] == 'd' && !root->opened && !opt->dir_found)
	{
		root->opened = 1;
		opt->dir_found = 1;
		*path = root->path;
		return ;
	}
	if (root->left)
		find_dir(root->left, path, opt);
	return ;
}

static void	find_dir_reverse(t_ls *root, char **path, t_option *opt)
{
	if (!root)
		return ;
	if (root->left)
		find_dir_reverse(root->left, path, opt);
	if (root->perm[0] == 'd' && !root->opened && !opt->dir_found)
	{
		root->opened = 1;
		opt->dir_found = 1;
		*path = root->path;
		return ;
	}
	if (root->right)
		find_dir_reverse(root->right, path, opt);
	return ;
}

void		print_dir(t_ls *root, t_option *opt, int nb_dir, int ac)
{
	t_ls	*new_root;
	char	*path;

	if (!nb_dir)
		return ;
	opt->dir_found = 0;
	if (!opt->r)
		find_dir(root, &path, opt);
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
	free_nodes(&new_root);
}
