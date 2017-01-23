/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:57:31 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/23 20:19:12 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	form_dir_tree(char *path, t_ls *root, t_option *opt)
{
	DIR			*dir;
	t_dirent	*dirent;
	t_ls		*new;

	dir = opendir(path);
	dirent = (t_dirent*)ft_memalloc(sizeof(t_dirent));
	while ((dirent = readdir(dir)))
	{
		if (root->name == NULL)
		{
			root->name = ft_strdup(dirent->d_name);
			root = get_stat(path, root);
		}
		else
		{
			new = (t_ls*)ft_memalloc(sizeof(t_ls));
			new->name = ft_strdup(dirent->d_name);
			new = get_stat(path, new);
			if (opt->t)
				add_node_time(new, root);
			else
				add_node_default(new, root);
		}
	}
	closedir(dir);
}

