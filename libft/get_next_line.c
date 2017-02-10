/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:36:45 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/26 11:53:12 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_get	*find_fd(int fd, t_get **lst)
{
	t_get	*tmp;
	t_get	*new;

	if (*lst == NULL)
	{
		if (!(*lst = ft_memalloc(sizeof(t_get))))
			return (NULL);
		(*lst)->fd = fd;
		return (*lst);
	}
	tmp = *lst;
	while (tmp->next != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	if (!(new = ft_memalloc(sizeof(t_get))))
		return (NULL);
	new->fd = fd;
	tmp->next = new;
	return (new);
}

int		check_stock(t_get *std, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (std->stock[i] && std->stock[i] != '\n')
		i++;
	if (!(*line = ft_strndup(std->stock, i)))
		return (-1);
	if (std->stock[i] == '\n')
	{
		i++;
		tmp = std->stock;
		if (!(std->stock = ft_strsub(std->stock, i, ft_strlen(std->stock) - i)))
			return (-1);
		free(tmp);
		return (1);
	}
	std->stock = NULL;
	return (0);
}

int		create_line(char **line, char *buf, t_get *std, int i)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strnjoin(*line, buf, i)))
		return (-1);
	free(tmp);
	tmp = std->stock;
	if (!(std->stock = ft_strdup(buf + i + 1)))
		return (-1);
	free(tmp);
	return (1);
}

int		read_file(int fd, t_get *std, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			return (create_line(line, buf, std, i));
		else
		{
			tmp = *line;
			if (!(*line = ft_strnjoin(*line, buf, ret)))
				return (-1);
			free(tmp);
		}
	}
	return (ft_strlen(*line) > 0 ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_get	*begin_lst = NULL;
	t_get			*std;
	int				ctrl;

	ctrl = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	std = find_fd(fd, &begin_lst);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (std->stock != NULL && (ctrl = check_stock(std, line)) == 1)
		return (1);
	if (ctrl == -1)
		return (-1);
	if ((ctrl = read_file(fd, std, line)) == 1)
		return (1);
	return (ctrl == -1 ? -1 : 0);
}
