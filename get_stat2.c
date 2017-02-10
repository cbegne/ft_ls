/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:00:08 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/10 16:24:09 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_perm(char *perm, mode_t mode)
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
	perm[10] = 0;
	if (mode & S_ISUID)
		perm[3] = (perm[3] == 'x' ? 's' : 'S');
	if (mode & S_ISGID)
		perm[6] = (perm[6] == 'x' ? 's' : 'S');
	if (mode & S_ISVTX)
		perm[9] = (perm[9] == 'x' ? 't' : 'T');
}

void		get_type_perm(char *perm, mode_t mode)
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
	get_perm(perm, mode);
}

void		get_time(t_ls *list, time_t mtime)
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
