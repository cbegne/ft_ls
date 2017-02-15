/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:22:28 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/07 18:16:57 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*new;
	t_list	*tmp;

	begin_lst = f(lst);
	if (!(begin_lst = ft_lstnew(begin_lst->content, begin_lst->content_size)))
		return (NULL);
	tmp = begin_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (begin_lst);
}
