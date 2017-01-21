/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:03:05 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/21 17:37:36 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/libft.h"
// #include "../ft_printf/includes/ft_printf.h"
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

	dev_t			rdev;
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

	struct s_ls		*right;
	struct s_ls		*left;
}					t_ls;

void	get_option(t_option *opt, char *av); 
void	error_usage(char c);
t_ls	*get_stat(int ac, char *arg, t_ls *list);
void	get_type_perm(char *perm, mode_t mode);
void	get_time(t_ls *list, time_t time);
void	form_tree(int ac, char **arg, t_ls **root, t_option *opt);

#endif
