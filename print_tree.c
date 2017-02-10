/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:33:39 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/10 17:23:10 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_line(t_ls *root, t_pad *p, t_option *opt)
{
	char	buf[PATH_MAX];

	if (opt->l)
	{
		ft_printf("%s  ", root->perm);
		ft_printf("%*hu ", p->len_lnk, root->nlink);
		ft_printf("%-*s  ", p->len_uid, root->uid);
		ft_printf("%-*s  ", p->len_gid, root->gid);
		if (root->perm[0] != 'c' && root->perm[0] != 'b')
			ft_printf("%*zu ", p->len_size, root->size);
		else
		{
			ft_printf(" %*d, ", p->len_maj, root->maj);
			ft_printf("%*d ", p->len_min, root->min);
		}
		ft_printf("%s ", root->date);
	}
	ft_printf("%s", root->name);
	if (opt->p && root->perm[0] == 'd')
		ft_printf("/");
	if (opt->l && root->perm[0] == 'l')
	{
		ft_bzero(buf, PATH_MAX);
		readlink(root->path, buf, PATH_MAX);
		ft_printf(" -> %s", buf);
	}
	ft_printf("\n");
}

static void	print_tree(t_ls *root, t_pad *p, int dir, t_option *opt)
{
	if (!root)
		return ;
	if (root->right)
		print_tree(root->right, p, dir, opt);
	if (!root->error && ((dir == 0 && root->perm[0] != 'd') || dir))
	{
		opt->print = 1;
		print_line(root, p, opt);
	}
	if (root->error)
		opt->print = 0;
	if (root->left)
		print_tree(root->left, p, dir, opt);
}

static void	print_tree_reverse(t_ls *root, t_pad *p, int dir, t_option *opt)
{
	if (!root)
		return ;
	if (root->left)
		print_tree_reverse(root->left, p, dir, opt);
	if (!root->error && ((dir == 0 && root->perm[0] != 'd') || dir))
	{
		opt->print = 1;
		print_line(root, p, opt);
	}
	if (root->error)
		opt->print = 0;
	if (root->right)
		print_tree_reverse(root->right, p, dir, opt);
}

void		print_files(t_ls *root, t_option *opt, int dir)
{
	t_pad	*p;

	p = (t_pad*)ft_memalloc(sizeof(t_pad));
	get_print_padding(p, root, dir);
	if (dir && opt->l)
		ft_printf("total %lld\n", p->tot_blocks);
	if (opt->r)
		print_tree_reverse(root, p, dir, opt);
	else
		print_tree(root, p, dir, opt);
	free(p);
}
