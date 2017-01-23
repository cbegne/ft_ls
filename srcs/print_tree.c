/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:33:39 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/23 20:13:31 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_tree(t_ls *root)
{
	if (!root)
		return ;
	if (root->right)
		print_tree(root->right);
	printf("print %s ", root->name);
	printf("%s\n", root->perm);
	if (root->left)
		print_tree(root->left);
}

// print_tree_reverse

void	ls_print_tree(t_ls *root, t_option *opt)
{
	if (!opt->r)
//		print_tree_reverse(root);
//	else
		print_tree(root);
}
