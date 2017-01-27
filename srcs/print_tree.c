/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:33:39 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/27 18:13:40 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_line(t_ls *root, t_pad *p, int dir)
{
	if ((dir == 0 && root->perm[0] == '-') || dir)
	{
		ft_printf("%s  ", root->perm);
		ft_printf("%*hu ", p->len_lnk, root->nlink);
		ft_printf("%*s  ", p->len_uid, root->uid);
		ft_printf("%*s  ", p->len_gid, root->gid);
		ft_printf("%*zu ", p->len_size, root->size);
		ft_printf("%s ", root->date);
		ft_printf("%s\n", root->name);
	}
	// maj min
}

static void	print_tree(t_ls *root, t_pad *p, int dir)
{
	if (!root)
		return ;
	if (root->right)
		print_tree(root->right, p, dir);
	print_line(root, p, dir);
	if (root->left)
		print_tree(root->left, p, dir);
}
/**
static void	print_tree_reverse(t_ls *root, t_pad *p)
{
	if (!root)
		return ;
	if (root->left)
		print_tree(root->left, p);
	print_line(root, p);
	if (root->right)
		print_tree(root->right, p);
}
**/
void	print_files(t_ls *root, t_option *opt, int dir)
{
	t_pad	*p;
	
	p = (t_pad*)ft_memalloc(sizeof(t_pad));
	get_print_padding(p, root, dir);
	if (!opt->r)
//		print_tree_reverse(root, p);
//	else
		print_tree(root, p, dir);
	free(p);
}

void	print_dir(t_ls **root, t_option *opt, int dir)
{
	t_ls	*new_root;
	char	*path;


	find_dir(*root, &path);
	printf("dir %s\n", path);
	(*root)->nb_dir--;
//	printf("open %d\n", (*root)->opened);
	new_root = (t_ls*)ft_memalloc(sizeof(t_ls));
	form_dir_tree(path, new_root, opt);
	print_files(new_root, opt, dir);
	free(new_root);
}



//	printf("lnk %zu\n", p->len_lnk);
//	printf("name %zu\n", p->len_uid);
//	printf("group %zu\n", p->len_gid);
//	printf("size %zu\n", p->len_size);
//	printf("maj %zu\n", p->len_maj);
//	printf("min %zu\n", p->len_min);
