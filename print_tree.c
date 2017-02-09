/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:33:39 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/09 12:39:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_line(t_ls *root, t_pad *p, int dir, t_option *opt)
{
	char	buf[NAME_MAX + 1];

	if (!root->error && ((dir == 0 && root->perm[0] != 'd') || dir))
	{
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
		if (opt->l && root->perm[0] == 'l')
		{
			ft_bzero(buf, sizeof(char*));
			readlink(root->path, buf, NAME_MAX);
			ft_printf(" -> %s", buf);
		}
		ft_printf("\n");
	}
}

static void	print_tree(t_ls *root, t_pad *p, int dir, t_option *opt)
{
	if (!root)
		return ;
	if (root->right)
		print_tree(root->right, p, dir, opt);
	print_line(root, p, dir, opt);
	if (root->left)
		print_tree(root->left, p, dir, opt);
}

static void	print_tree_reverse(t_ls *root, t_pad *p, int dir, t_option *opt)
{
	if (!root)
		return ;
	if (root->left)
		print_tree_reverse(root->left, p, dir, opt);
	print_line(root, p, dir, opt);
	if (root->right)
		print_tree_reverse(root->right, p, dir, opt);
}

void	print_files(t_ls *root, t_option *opt, int dir)
{
	t_pad	*p;
	
	p = (t_pad*)ft_memalloc(sizeof(t_pad));
//	ft_printf("name %s\n", root->name);
	get_print_padding(p, root, dir);
	if (dir && opt->l)
		ft_printf("total %lld\n", p->tot_blocks);
	if (opt->r)
		print_tree_reverse(root, p, dir, opt);
	else
		print_tree(root, p, dir, opt);
//	free(p);
}

void	print_dir(t_ls *root, t_option *opt, int nb_dir, int ac)
{
	t_ls	*new_root;
	char	*path;

	if (nb_dir == 0)
		return ;
	opt->done = 0;
	if (!opt->r)
		find_dir(root, &path);
	else
		find_dir_reverse(root, &path, opt);
//	ft_printf("path ici %s\n", path);
	if (ac > 1)
		ft_printf("%s:\n", path);
	new_root = (t_ls*)ft_memalloc(sizeof(t_ls));
	form_dir_tree(path, new_root, opt);
	if (new_root->name)
		print_files(new_root, opt, root->nb_dir);
	root->nb_dir--;
	while (opt->upper_r && new_root->nb_dir)
	{
		ft_printf("\n");
		print_dir(new_root, opt, new_root->nb_dir, 2);
	}
	free(new_root);
}

//	printf("lnk %zu\n", p->len_lnk);
//	printf("name %zu\n", p->len_uid);
//	printf("group %zu\n", p->len_gid);
//	printf("size %zu\n", p->len_size);
//	printf("maj %zu\n", p->len_maj);
//	printf("min %zu\n", p->len_min);
