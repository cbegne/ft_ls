/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:53:01 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/23 20:19:15 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_node_default(t_ls *new, t_ls *tmp)
{
	while (tmp)
	{
		if (ft_strcmp(new->name, tmp->name) < 0)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new;
				return ;
			}
			tmp = tmp->right;
		}
		else
		{
			if (tmp->left == NULL)
			{
				tmp->left = new;
				return ;
			}
			tmp = tmp->left;
		}
	}
}

void	add_node_time(t_ls *new, t_ls *tmp)
{
	while (tmp)
	{
		if (new->time > tmp->time)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new;
				return ;
			}
			tmp = tmp->right;
		}
		else
		{
			if (tmp->left == NULL)
			{
				tmp->left = new;
				return ;
			}
			tmp = tmp->left;
		}
	}
}

void	form_tree(int ac, char **arg, t_ls **root, t_option *opt)
{
	int		i;
	t_ls	*new;

	i = 0;
	*root = (t_ls*)ft_memalloc(sizeof(t_ls));
	if (ac == 0 || !ft_strcmp(*arg, ".") || !ft_strcmp(*arg, "./"))
	{
		ac == 0 ? form_dir_tree(".", *root, opt) : form_dir_tree(*arg, *root, opt);
		return ;
	}
	else
		*root = get_stat(arg[i++], *root);
	while (i < ac)
	{
		new = (t_ls*)ft_memalloc(sizeof(t_ls));
		new = get_stat(arg[i], new);
		if (opt->t)
			add_node_time(new, *root);
		else
			add_node_default(new, *root);
		i++;
	}
}
