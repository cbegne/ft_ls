/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_dir_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/18 20:51:59 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			do_not_open(t_ls *list)
{
	if (!ft_strcmp(list->name, ".") || !ft_strcmp(list->name, ".."))
		return (1);
	return (0);
}

static char	*error_name(char *path)
{
	char	*name;
	int		len;
	int		i;

	len = ft_strlen(path);
	i = len;
	while (i >= 0 && path[i] != '/')
		i--;
	name = ft_strdup(path + i + 1);
	return (name);
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
	char		*name;

	if ((dir = opendir(path)) == NULL)
	{
		name = error_name(path);
		ls_error(name, errno);
		free(name);
		return ;
	}
	while ((dirent = readdir(dir)))
	{
		if (opt->a || (!opt->a && dirent->d_name[0] != '.'))
			get_elem(path, root, dirent, opt);
	}
	closedir(dir);
}
