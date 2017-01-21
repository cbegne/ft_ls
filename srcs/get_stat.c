/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:10:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/21 17:37:26 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_uid_gid(t_ls *list, t_stat *stat)
{
	t_passwd	passwd;
	t_group		group;

	passwd = *getpwuid(stat->st_uid);
	list->uid = ft_strdup(passwd.pw_name);
//	printf("uid %s\n", list->uid);
	group = *getgrgid(stat->st_gid);
	list->gid = ft_strdup(group.gr_name);
//	printf("gid %s\n", list->gid);
//
}

static void	get_path_name(int ac, char *arg, char **path, char **name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg);
	*name = NULL;
	if (ac == 0 || ft_strcmp(arg, ".") == 0 || ft_strcmp(arg, "./") == 0)
		*path = ft_strdup(".");
	else
	{
		*path = ft_strdup(arg);
		while (arg[i] && arg[i] == '/')
			i++;
		if (i == len--)
			*name = ft_strdup("/");
		else
		{
			while (len >= 0 && arg[len] == '/')
				len--;
			i = len;
			while (i >= 0 && arg[i] != '/')
				i--;
			*name = ft_strsub(arg, i + 1, len - i);
		}
	}
}

static t_ls	*get_all_info(char *path, char *name, t_stat *stat, t_ls *new)
{
	new->rdev = stat->st_rdev;
	new->mode = stat->st_mode;
	new->nlink = stat->st_nlink;
	new->size = stat->st_size;
	new->time = stat->st_mtime;
	new->blocks = stat->st_blocks;
	new->path = path;
	new->name = name;
	get_uid_gid(new, stat);
	get_time(new, new->time);
	get_type_perm(new->perm, new->mode);
	new->right = NULL;
	new->left = NULL;
	return (new);
}


t_ls	*get_stat(int ac, char *arg, t_ls *list)
{
	char	*path;
	char	*name;
	t_stat	stat;

	get_path_name(ac, arg, &path, &name);
//	printf("ac %d av %s\n", ac, arg);
	lstat(path, &stat);
	list = get_all_info(path, name, &stat, list);
	return (list);
}
