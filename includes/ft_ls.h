/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:03:05 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 09:45:48 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <errno.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef	struct	s_pad
{
	size_t		len_lnk;
	size_t		len_uid;
	size_t		len_gid;
	size_t		len_size;
	size_t		len_min;
	size_t		len_maj;
	blkcnt_t	tot_blocks;
}				t_pad;

typedef struct	s_option
{
	int			l;
	int			a;
	int			r;
	int			upper_r;
	int			t;
	int			p;
	int			u;
	int			d;
	int			c;
	int			upper_a;
	int			dir_found;
	int			print;
}				t_option;

typedef struct	s_ls
{
	mode_t		mode;
	nlink_t		nlink;
	char		*uid;
	char		*gid;
	off_t		size;
	time_t		time;
	long		ntime;
	char		*date;
	blkcnt_t	blocks;
	char		*path;
	char		*name;
	char		perm[12];
	int			maj;
	int			min;
	int			nb_dir;
	int			opened;
	int			error;
	struct s_ls	*right;
	struct s_ls	*left;
}				t_ls;

int				get_option(t_option *opt, char **av);
t_ls			*get_stat(char *arg, t_ls *list, t_option *opt);
void			get_type_perm(char *perm, mode_t mode, char *path);
void			get_time(t_stat *stat, t_ls *new, t_option *opt);
void			get_date(t_ls *list, time_t time);
void			form_tree(int ac, char **arg, t_ls **root, t_option *opt);
void			form_dir_tree(char *path, t_ls *root, t_option *opt);
void			add_node(t_ls *new, t_ls *root, t_option *opt);
void			find_dir(t_ls *root, char **path, t_option *opt);
void			find_dir_reverse(t_ls *root, char **path, t_option *opt);
int				do_not_open(t_ls *list);
void			get_print_padding(t_pad *p, t_ls *root, int dir);
void			print_files(t_ls *root, t_option *opt, int dir);
void			print_dir(t_ls *root, t_option *opt, int nb_dir, int ac);
void			ls_error(char *str, int errnum);
void			error_usage(char c);
void			free_nodes(t_ls **root);

#endif
