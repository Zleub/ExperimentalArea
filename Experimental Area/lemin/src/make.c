/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:02:52 by adebray           #+#    #+#             */
/*   Updated: 2014/03/23 17:37:41 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			fill_data(char *str, t_data *data, t_room **room, t_pipe **pipe)
{
	t_pipe *tmp_pipe;

	tmp_pipe = NULL;
	if (str[0] == '#' && str[1] != '#')
		;
	else if (str[0] == '#' && str[1] == '#')
		start_end(str, data, &(*room));
	else if (is_room(str) && data->lemin_nb)
		preget_room(data, room, str);
	else if (is_pipe(str) && data_valid(data))
		preget_pipe(data, pipe, str);
	else
		return (-1);
	return (0);
}

t_room		*get_next(t_room *head_path, char *str)
{
	t_room		*tmp_path;

	tmp_path = head_path;
	while (tmp_path->next)
		tmp_path = tmp_path->next;
	tmp_path->next = create_room();
	tmp_path = tmp_path->next;
	tmp_path->str = str;
	return (tmp_path);
}

int			find_next(t_data *data, t_pipe **dst, t_pipe *pipe, t_room *path)
{
	t_room		*tmp_path;
	t_pipe		*tmp_pipe;
	int			i;

	tmp_pipe = pipe;
	while (tmp_pipe)
	{
		i = 0;
		while (dst[i])
		{
			if (!ft_strcmp(dst[i]->src, data->end))
			{
				tmp_path = get_next(path, dst[i]->src);
				return (1);
			}
			if (!ft_strcmp(tmp_pipe->src, dst[i]->src))
			{
				tmp_path = get_next(path, tmp_pipe->src);
				return (find_next(data, tmp_pipe->dst, pipe, path));
			}
			i += 1;
		}
		tmp_pipe = tmp_pipe->next;
	}
	return (0);
}

t_room		*get_path(t_data *data, t_pipe *head_pipe)
{
	t_room			*head_path;
	t_room			*tmp_path;
	t_pipe			*tmp_pipe;

	tmp_pipe = head_pipe;
	head_path = NULL;
	tmp_path = NULL;
	while (tmp_pipe)
	{
		if (!ft_strcmp(data->start, tmp_pipe->src))
		{
			head_path = create_room();
			head_path->str = tmp_pipe->src;
			if (!find_next(data, tmp_pipe->dst, head_pipe, head_path))
				return (NULL);
		}
		tmp_pipe = tmp_pipe->next;
	}
	return (head_path);
}

void		free_last_gnl(t_gnl *tmp)
{
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
}
