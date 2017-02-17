/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_dir_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 16:49:53 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			do_not_open(t_ls *list)
{
	if (!ft_strcmp(list->name, ".") || !ft_strcmp(list->name, ".."))
		return (1);
	return (0);
}

static void	new_elem(char *path, t_ls *list, t_ls *root, t_option *opt)
{
	list = get_stat(path, list, opt);
	if (list->perm[0] == 'd')
		root->nb_dir++;
	if (opt->upper_r && do_not_open(list))
	{
		list->opened = 1;
		root->nb_dir--;
	}
}

static void	get_elem(char *path, t_ls *root, t_dirent *dirent, t_option *opt)
{
	t_ls	*new;

	if (root->name == NULL)
	{
		root->name = ft_strdup(dirent->d_name);
		new_elem(path, root, root, opt);
	}
	else
	{
		new = (t_ls*)ft_memalloc(sizeof(t_ls));
		new->name = ft_strdup(dirent->d_name);
		new_elem(path, new, root, opt);
		add_node(new, root, opt);
	}
}

void		form_dir_tree(char *path, t_ls *root, t_option *opt)
{
	DIR			*dir;
	t_dirent	*dirent;

	if ((dir = opendir(path)) == NULL)
	{
		ls_error(path, errno);
		return ;
	}
	while ((dirent = readdir(dir)))
	{
		if (opt->a || (!opt->a && dirent->d_name[0] != '.'))
			get_elem(path, root, dirent, opt);
	}
	closedir(dir);
}
