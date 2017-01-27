/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_print_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:11:29 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/27 16:33:43 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	size_t	count_size(size_t nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	padding(t_pad *p, t_ls *root, int dir)
{
	if ((dir == 0 && root->perm[0] == '-') || dir)
	{
		if (count_size((size_t)root->nlink) > p->len_lnk)
			p->len_lnk = count_size((size_t)root->nlink);
		if (ft_strlen(root->uid) > p->len_uid)
			p->len_uid = ft_strlen(root->uid);
		if (ft_strlen(root->gid) > p->len_gid)
			p->len_gid = ft_strlen(root->gid);
		if (count_size((size_t)root->size) > p->len_size)
			p->len_size = count_size((size_t)root->size);
		if (count_size((size_t)root->maj) > p->len_maj)
			p->len_maj = count_size((size_t)root->maj);
		if (count_size((size_t)root->min) > p->len_min)
			p->len_min = count_size((size_t)root->min);
	}
//	printf("name pad %s ", root->name);
//	printf("lnk %hu\n", root->nlink);
}

void	get_print_padding(t_pad *p, t_ls *root, int dir)
{
	if (!root)
		return ;
	if (root->right)
		get_print_padding(p, root->right, dir);
	padding(p, root, dir);
	if (root->left)
		get_print_padding(p, root->left, dir);
}
