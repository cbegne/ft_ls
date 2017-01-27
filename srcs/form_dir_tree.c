/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_dir_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/27 18:13:30 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	form_dir_tree(char *path, t_ls *root, t_option *opt)
{
	DIR			*dir;
	t_dirent	*dirent;
	t_ls		*new;
	int			excl;

	dir = opendir(path);
	dirent = (t_dirent*)ft_memalloc(sizeof(t_dirent));
	while ((dirent = readdir(dir)))
	{
		excl = 0;
		if (opt->a == 0 && dirent->d_name[0] == '.')
			excl = 1;
		if (root->name == NULL && excl == 0)
		{
			root->name = ft_strdup(dirent->d_name);
			root = get_stat(path, root);
			if (root->perm[0] == 'd')
				root->nb_dir++;
		}
		else if (excl == 0)
		{
			new = (t_ls*)ft_memalloc(sizeof(t_ls));
			new->name = ft_strdup(dirent->d_name);
			new = get_stat(path, new);
			if (new->perm[0] == 'd')
				root->nb_dir++;
			add_node(new, root, opt);
		}
	}
	free(dirent);
	closedir(dir);
}

void	find_dir(t_ls *root, char **path)
{
	if (!root)
		return ;
	if (root->right)
		find_dir(root->right, path);
	if (root->perm[0] == 'd' && root->opened == 0)
	{
		root->opened = 1;
		*path = root->path;
		return ;
	}
	if (root->left)
		find_dir(root->left, path);
	return ;
}
