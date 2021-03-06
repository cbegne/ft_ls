/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_print_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:11:29 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 15:53:08 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	count_size(size_t nb)
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

static void		padding(t_pad *p, t_ls *root, int dir)
{
	if (!root->error && ((dir == 0 && root->perm[0] != 'd') || dir))
	{
		if (count_size((size_t)root->nlink) > p->len_lnk)
			p->len_lnk = count_size((size_t)root->nlink);
		if (ft_strlen(root->uid) > p->len_uid)
			p->len_uid = ft_strlen(root->uid);
		if (ft_strlen(root->gid) > p->len_gid)
			p->len_gid = ft_strlen(root->gid);
		if (count_size((size_t)root->size) > p->len_size)
			p->len_size = count_size((size_t)root->size);
		if (root->maj && count_size((size_t)root->maj) > p->len_maj)
			p->len_maj = count_size((size_t)root->maj);
		if (root->min && count_size((size_t)root->min) > p->len_min)
			p->len_min = count_size((size_t)root->min);
		if (p->len_min && p->len_maj && \
				p->len_size < (p->len_min + p->len_maj + 3))
			p->len_size = p->len_min + p->len_maj + 3;
		p->tot_blocks = p->tot_blocks + root->blocks;
	}
}

void			get_print_padding(t_pad *p, t_ls *root, int dir)
{
	if (!root)
		return ;
	if (root->right)
		get_print_padding(p, root->right, dir);
	padding(p, root, dir);
	if (root->left)
		get_print_padding(p, root->left, dir);
}
