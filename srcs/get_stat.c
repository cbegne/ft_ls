/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:10:06 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/23 20:29:40 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_full_path(char *path, t_ls *new)
{
	int		len;
	char	*tmp;

	len = ft_strlen(path);
	tmp = NULL;
	if (ft_strcmp(path, new->name))
	{
		if (path[len - 1] == '/')
			new->path = ft_strjoin(path, new->name);
		// seg fault ./
		else
			tmp = ft_strjoin(path, "/");
			new->path = ft_strjoin(tmp, new->name);
			ft_strdel(&tmp);
	}
	else
		new->path = ft_strdup(new->name);
	printf("pth %s\n", new->path);
}

static void	get_uid_gid(t_ls *new, t_stat *stat)
{
	t_passwd	passwd;
	t_group		group;

	passwd = *getpwuid(stat->st_uid);
	new->uid = ft_strdup(passwd.pw_name);
	group = *getgrgid(stat->st_gid);
	new->gid = ft_strdup(group.gr_name);
}
/**
static void	clean_path(char *path, char **name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(path);
	while (path[i] && path[i] == '/')
		i++;
	if (i == len--)
		*name = ft_strdup("/");
	else
	{
		while (len >= 0 && path[len] == '/')
			len--;
		i = len;
		while (i >= 0 && path[i] != '/')
			i--;
		*name = ft_strsub(path, i + 1, len - i);
	}
}
**/
static t_ls	*get_all_info(t_stat *stat, t_ls *new)
{
	new->rdev = stat->st_rdev;
	new->mode = stat->st_mode;
	new->nlink = stat->st_nlink;
	new->size = stat->st_size;
	new->time = stat->st_mtime;
	new->blocks = stat->st_blocks;
	get_uid_gid(new, stat);
	get_time(new, new->time);
	get_type_perm(new->perm, new->mode);
	new->right = NULL;
	new->left = NULL;
	return (new);
}


t_ls	*get_stat(char *path, t_ls *new)
{
	t_stat	stat;

	if (new->name == NULL)
		new->name = ft_strdup(path);
	get_full_path(path, new);
	lstat(new->path, &stat);
	new = get_all_info(&stat, new);
	return (new);
}
