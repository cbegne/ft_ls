/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:46:33 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/15 11:53:30 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_nodes(t_ls **root)
{
	if (!(*root))
		return ;
	if ((*root)->right)
		free_nodes(&(*root)->right);
	if ((*root)->left)
		free_nodes(&(*root)->left);
	ft_memdel((void**)&((*root)->name));
	ft_memdel((void**)&((*root)->path));
	ft_memdel((void**)&((*root)->date));
	ft_memdel((void**)&((*root)->uid));
	ft_memdel((void**)&((*root)->gid));
	ft_memdel((void**)root);
}
