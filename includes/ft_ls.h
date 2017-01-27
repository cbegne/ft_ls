/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:03:05 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/27 18:11:50 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include <grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef	struct	s_pad
{
	size_t			len_lnk;
	size_t			len_uid;
	size_t			len_gid;
	size_t			len_size;
	size_t			len_min;
	size_t			len_maj;
}				t_pad;

typedef struct	s_option
{
	int			l;
	int			a;
	int			r;
	int			upper_r;
	int			t;
}				t_option;

typedef struct		s_ls
{

//	dev_t			rdev;
	mode_t			mode;
	nlink_t			nlink;
	char			*uid;
	char			*gid;
	off_t			size;
	time_t			time;
	char			*date;
	blkcnt_t		blocks;
	
	char			*path;
	char			*name;
	char			perm[11];

	int				maj;
	int				min;

	int				nb_dir;
	int				opened;

	struct s_ls		*right;
	struct s_ls		*left;
}					t_ls;

void	get_option(t_option *opt, char *av); 
void	error_usage(char c);
t_ls	*get_stat(char *arg, t_ls *list);
void	get_type_perm(char *perm, mode_t mode);
void	get_time(t_ls *list, time_t time);
void	get_full_path(char *path, t_ls *new);
void	form_tree(int ac, char **arg, t_ls **root, t_option *opt);
void	form_dir_tree(char *path, t_ls *root, t_option *opt);
void	add_node(t_ls *new, t_ls *root, t_option *opt);
void	add_node_default(t_ls *new, t_ls *tmp);
void	add_node_time(t_ls *new, t_ls *tmp);
void	get_print_padding(t_pad *p, t_ls *root, int dir);

void	find_dir(t_ls *root, char **path);

void	print_files(t_ls *root, t_option *opt, int dir);
void	print_dir(t_ls **root, t_option *opt, int dir);

#endif
