/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_dir_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 11:19:12 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	new_elem(char *path, t_ls *list, t_ls *root, t_option *opt)
{
	list = get_stat(path, list, opt);
	if (list->perm[0] == 'd')
		root->nb_dir++;
}

static void	get_elem(char *path, t_ls *root, t_dirent *dirent, t_option *opt)
{
	t_ls	*new;

	if (root->name == NULL)
	{
		root->name = ft_strdup(dirent->d_name);
		new_elem(path, root, root, opt);
		if (opt->upper_r && do_not_open(root))
		{
			root->opened = 1;
			root->nb_dir--;
		}
	}
	else
	{
		new = (t_ls*)ft_memalloc(sizeof(t_ls));
		new->name = ft_strdup(dirent->d_name);
		new_elem(path, new, root, opt);
		if (opt->upper_r && do_not_open(new))
		{
			new->opened = 1;
			root->nb_dir--;
		}
		add_node(new, root, opt);
	}
}

void		form_dir_tree(char *path, t_ls *root, t_option *opt)
{
	DIR			*dir;
	t_dirent	*dirent;
	int			excl;

	if ((dir = opendir(path)) == NULL)
	{
		ls_error(path, errno);
		return ;
	}
	while ((dirent = readdir(dir)))
	{
		excl = 0;
		if (opt->a == 0 && dirent->d_name[0] == '.')
			excl = 1;
		else if (excl == 0)
			get_elem(path, root, dirent, opt);
	}
	closedir(dir);
}

void		find_dir(t_ls *root, char **path, t_option *opt)
{
	if (!root)
		return ;
	if (root->right)
		find_dir(root->right, path, opt);
	if (root->perm[0] == 'd' && root->opened == 0 && opt->dir_found == 0)
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

void		find_dir_reverse(t_ls *root, char **path, t_option *opt)
{
	if (!root)
		return ;
	if (root->left)
		find_dir_reverse(root->left, path, opt);
	if (root->perm[0] == 'd' && root->opened == 0 && opt->dir_found == 0)
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
