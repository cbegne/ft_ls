/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_dir_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/09 12:39:02 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void new_elem(char *path, t_ls *list, t_ls *root, t_dirent *dirent)
{
		list->name = ft_strdup(dirent->d_name);
		list = get_stat(path, list);
		if (list->perm[0] == 'd')
			root->nb_dir++;
}

void	form_dir_tree(char *path, t_ls *root, t_option *opt)
{
	DIR			*dir;
	t_dirent	*dirent;
	int			excl;
	t_ls	*new;

	if ((dir = opendir(path)) == NULL)
	{
		ls_error(path, errno);
		return ;
	}
	dirent = (t_dirent*)ft_memalloc(sizeof(t_dirent));
	while ((dirent = readdir(dir)))
	{
		excl = 0;
		if (opt->a == 0 && dirent->d_name[0] == '.')
			excl = 1;
		if (root->name == NULL && excl == 0)
			new_elem(path, root, root, dirent);			
		else if (excl == 0)
		{
			new = (t_ls*)ft_memalloc(sizeof(t_ls));
			new_elem(path, new, root, dirent);
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
	{
	//	ft_printf("right");
		find_dir(root->right, path);
	}
	if (root->perm[0] == 'd' && root->opened == 0)
	{
		root->opened = 1;
		*path = root->path;
	//	ft_printf("pth here %s\n", *path);
		return ;
	}
	if (root->left)
	{
	//	ft_printf("left");
		find_dir(root->left, path);
	}
	return ;
}

void	find_dir_reverse(t_ls *root, char **path, t_option *opt)
{
	if (!root)
		return ;
	if (root->left)
	{
//		ft_printf("left");
		find_dir_reverse(root->left, path, opt);
	}
	if (root->perm[0] == 'd' && root->opened == 0 && opt->done == 0)
	{
		root->opened = 1;
		opt->done = 1;
		*path = root->path;
//		ft_printf("pth here %s\n", *path);
		return ;
	}
	if (root->right)
	{
//		ft_printf("right");
		find_dir_reverse(root->right, path, opt);
	}
	return ;
}
