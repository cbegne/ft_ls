/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:26:49 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/14 19:36:47 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_node(t_ls **root)
{
	if (!(*root))
		return ;
	if ((*root)->right)
		free_node(&(*root)->right);
	ft_memdel((void**)&((*root)->name));
	ft_memdel((void**)&((*root)->path));
	ft_memdel((void**)&((*root)->date));
	ft_memdel((void**)&((*root)->uid));
	ft_memdel((void**)&((*root)->gid));
	ft_memdel((void**)root);
	if ((*root)->left)
		free_node(&(*root)->left);
}
