/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/22 13:20:52 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		data_valid(t_data *data)
{
	if (data->lemin_nb == 0 || data->room_nb == 0)
		return (0);
	else if (data->start == NULL || data->end == NULL)
		return (0);
	else
		return (1);
}

t_pipe		*get_pipe(t_pipe *head, t_data *data, char *part_1)
{
	while (head)
	{
		if (!ft_strcmp(head->src, part_1))
			return (head);
		else
		{
			if (head->next)
				head = head->next;
			else
			{
				head->next = create_pipe(data);
				return (head->next);
			}
		}
	}
	return (head->next);
}

int		fill_data(char *str, t_data *data, t_room **head_room, t_pipe **head_pipe)
{
	t_room *tmp_room;
	t_pipe *tmp_pipe;

	int		i;

	if (str[0] == '#' && str[1] != '#')
		;
	else if (str[0] == '#' && str[1] == '#')
		start_end(str, data, &(*head_room));
	else if (is_room(str) && data->lemin_nb)
	{
		if (*head_room)
		{
			tmp_room = create_room();
			tmp_room->next = (*head_room)->next;
			tmp_room->str = get_room(str);
			(*head_room)->next = tmp_room;
		}
		else
		{
			*head_room = create_room();
			(*head_room)->str = get_room(str);
		}
		data->room_nb += 1;
		ft_printf("ROOM----\n");
		print_room(*head_room);
		ft_printf("--------\n");
	}
	else if (is_pipe(str) && data_valid(data))
	{
		char	*part_1;
		char	*part_2;

		i = 0;
		while (str[i] != '-')
			i += 1;
		part_1 = ft_strsub(str, 0, i);
		part_2 = ft_strsub(str, i + 1, ft_strlen(str));


		if (*head_pipe)
		{
			tmp_pipe = get_pipe(*head_pipe, data, part_1);
			if (!tmp_pipe->src)
				tmp_pipe->src = part_1;
			i = 0;
			while (tmp_pipe->dst[i])
				i += 1;
			tmp_pipe->dst[i] = create_pipe(data);

			tmp_pipe->dst[i]->src = part_2;
		}
		else
		{
			*head_pipe = create_pipe(data);
			(*head_pipe)->src = part_1;
			(*head_pipe)->dst[0] = create_pipe(data);
			(*head_pipe)->dst[0]->src = part_2;
		}
		ft_printf("PIPE----\n");
		print_pipe(*head_pipe);
		ft_printf("--------\n");
	}
	else
		return (-1);
	return (0);
}
t_pipe			*find_next(t_data *data, char *dst_pipe, t_pipe *head_pipe, t_room *head_path)
{
	int			i;

	i = 0;
	while (head_pipe)
	{
		i = 0;
		while (head_pipe->dst[i])
		{
			ft_printf("!ft_strcmp(head_pipe->dst[%d]->src : %s, data-end %s\n", i, head_pipe->dst[i]->src, data->end);
			if (ft_strcmp(head_pipe->dst[i]->src, data->end))
			{
				ft_printf("is no end\n");
				return (find_next(data, head_pipe->dst[i]->src, head_pipe, head_path));
				i += 1;
			}
			else
			{
				ft_printf("return\n");
				return (head_pipe);
			}
		}
		head_pipe = head_pipe->next;
	}
}

t_room			*get_path(t_data *data, t_pipe *head_pipe)
{
	t_room			*head_path;
	t_room			*tmp_path;
	t_pipe			*tmp_pipe;
	int				i;

	tmp_pipe = head_pipe;
	tmp_path = NULL;
	while (tmp_pipe)
	{
		i = 0;
		while (tmp_pipe->dst[i])
		{
			if (!ft_strcmp(data->start, tmp_pipe->dst[i]->src))
			{
				ft_printf("got start\n");
				find_next(data, tmp_pipe->dst[i]->src, head_pipe, head_path);
			}
			i += 1;
		}
		tmp_pipe = tmp_pipe->next;
	}
	return (tmp_path);
}

void		free_last_gnl(t_gnl *tmp)
{
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
}

void	fill_gnl(t_gnl **head, t_data *data)
{
	t_gnl	*tmp;
	t_room	*head_room;
	t_pipe	*head_pipe;
	t_room	*head_path;

	tmp = create_gnl();
	*head = tmp;
	head_room = NULL;
	head_pipe = NULL;

	while (get_next_line(0, &tmp->str) > 0)
	{
		if (*tmp->str == '\0')
		{
			free_last_gnl(tmp);
			return ;
		}
		if (fill_data(tmp->str, data, &head_room, &head_pipe) == -1)
		{
			ft_printf("data error\n");
			return ;
		}
		tmp->next = create_gnl();
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	free_last_gnl(tmp);

	head_path = get_path(data, head_pipe);

	ft_printf("\npipe :\n");
	print_pipe(head_pipe);
	ft_printf("\nroom :\n");
	print_room(head_room);
	ft_printf("\npath :\n");
	if (head_path)
		print_room(head_path);
}

void	get_lemin(void)
{
	t_data	*data;
	t_gnl	*head;

	data = create_data();
	fill_gnl(&head, data);

	ft_printf("data :\n");
	print_data(data);
	ft_printf("gnl :\n");
	print_gnl(head);
}

int		main(void)
{
	get_lemin();
	return (0);
}
