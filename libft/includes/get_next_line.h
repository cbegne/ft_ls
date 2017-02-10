/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:53:32 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/10 17:39:46 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include <unistd.h>

typedef	struct		s_get
{
	char			*stock;
	int				fd;
	struct s_get	*next;
}					t_get;

int					get_next_line(const int fd, char **line);

#endif
