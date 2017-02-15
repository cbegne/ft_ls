/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:41:33 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/14 18:44:29 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_file_acl(char *path)
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

static void	get_perm(char *perm, mode_t mode, char *path)
{
	perm[1] = (mode & S_IRUSR ? 'r' : '-');
	perm[2] = (mode & S_IWUSR ? 'w' : '-');
	perm[3] = (mode & S_IXUSR ? 'x' : '-');
	perm[4] = (mode & S_IRGRP ? 'r' : '-');
	perm[5] = (mode & S_IWGRP ? 'w' : '-');
	perm[6] = (mode & S_IXGRP ? 'x' : '-');
	perm[7] = (mode & S_IROTH ? 'r' : '-');
	perm[8] = (mode & S_IWOTH ? 'w' : '-');
	perm[9] = (mode & S_IXOTH ? 'x' : '-');
	perm[10] = get_file_acl(path);
	perm[11] = 0;
	if (mode & S_ISUID)
		perm[3] = (perm[3] == 'x' ? 's' : 'S');
	if (mode & S_ISGID)
		perm[6] = (perm[6] == 'x' ? 's' : 'S');
	if (mode & S_ISVTX)
		perm[9] = (perm[9] == 'x' ? 't' : 'T');
}

void		get_type_perm(char *perm, mode_t mode, char *path)
{
	if (S_ISREG(mode))
		perm[0] = '-';
	else if (S_ISDIR(mode))
		perm[0] = 'd';
	else if (S_ISCHR(mode))
		perm[0] = 'c';
	else if (S_ISBLK(mode))
		perm[0] = 'b';
	else if (S_ISFIFO(mode))
		perm[0] = 'p';
	else if (S_ISLNK(mode))
		perm[0] = 'l';
	else if (S_ISSOCK(mode))
		perm[0] = 's';
	get_perm(perm, mode, path);
}

void		get_time(t_stat *stat, t_ls *new, t_option *opt)
{
	if (opt->u)
	{
		new->time = stat->st_atimespec.tv_sec;
		new->ntime = stat->st_atimespec.tv_nsec;
	}
	else if (opt->c)
	{
		new->time = stat->st_ctimespec.tv_sec;
		new->ntime = stat->st_ctimespec.tv_nsec;
	}
	else
	{
		new->time = stat->st_mtimespec.tv_sec;
		new->ntime = stat->st_mtimespec.tv_nsec;
	}
}

void		get_date(t_ls *list, time_t mtime)
{
	char	*long_date;
	time_t	now;

	long_date = ctime(&mtime);
	now = time(&now);
	if (long_date[20] == ' ')
		list->date = ft_strnnjoin(long_date + 4, " 10000", 7, 7);
	else if (now - mtime > 15778800 || now - mtime < -15778800)
		list->date = ft_strnnjoin(long_date + 4, long_date + 19, 7, 5);
	else
		list->date = ft_strndup(long_date + 4, 12);
}
