/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:53:01 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/14 18:01:56 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_node_default(t_ls *new, t_ls **tmp)
{
	t_ls	*tmp2;

	tmp2 = *tmp;
	if (ft_strcmp(new->name, (*tmp)->name) < 0)
	{
		*tmp = (*tmp)->right;
		if ((*tmp) == NULL)
		{
			tmp2->right = new;
			return ;
		}
	}
	else
	{
		*tmp = (*tmp)->left;
		if ((*tmp) == NULL)
		{
			tmp2->left = new;
			return ;
		}
	}
}

static void	add_node_ntime(t_ls *new, t_ls **tmp)
{
	t_ls	*tmp2;

	tmp2 = *tmp;
	if (new->ntime > (*tmp)->ntime)
	{
		*tmp = (*tmp)->right;
		if (*tmp == NULL)
		{
			tmp2->right = new;
			return ;
		}
	}
	else if (new->ntime < (*tmp)->ntime)
	{
		*tmp = (*tmp)->left;
		if (*tmp == NULL)
		{
			tmp2->left = new;
			return ;
		}
	}
	else if (new->ntime == (*tmp)->ntime)
		add_node_default(new, tmp);
}

static void	add_node_time(t_ls *new, t_ls **tmp)
{
	t_ls	*tmp2;

	tmp2 = *tmp;
	if (new->time > (*tmp)->time)
	{
		(*tmp) = (*tmp)->right;
		if (*tmp == NULL)
		{
			tmp2->right = new;
			return ;
		}
	}
	else if (new->time < (*tmp)->time)
	{
		(*tmp) = (*tmp)->left;
		if (*tmp == NULL)
		{
			tmp2->left = new;
			return ;
		}
	}
	else if (new->time == (*tmp)->time)
		add_node_ntime(new, tmp);
}

void		add_node(t_ls *new, t_ls *root, t_option *opt)
{
	t_ls	*tmp;

	tmp = root;
	if (opt->t)
	{
		while (tmp)
			add_node_time(new, &tmp);
	}
	else
	{
		while (tmp)
			add_node_default(new, &tmp);
	}
}

void		form_tree(int ac, char **arg, t_ls **root, t_option *opt)
{
	int		i;
	t_ls	*new;

	i = 0;
	*root = (t_ls*)ft_memalloc(sizeof(t_ls));
	if (ac == 0)
		*root = get_stat(".", *root, opt);
	else
		*root = get_stat(arg[i++], *root, opt);
	if ((*root)->perm[0] == 'd')
		(*root)->nb_dir = 1;
	while (i < ac)
	{
		new = (t_ls*)ft_memalloc(sizeof(t_ls));
		new = get_stat(arg[i], new, opt);
		if (new->perm[0] == 'd')
			(*root)->nb_dir++;
		add_node(new, *root, opt);
		i++;
	}
}
