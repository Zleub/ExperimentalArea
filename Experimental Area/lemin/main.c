/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/20 21:27:46 by Arno             ###   ########.fr       */
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
		ft_printf("ROOM-\n");
		print_room(*head_room);
		ft_printf("-----\n");
	}
	else if (is_pipe(str) && data_valid(data))
	{
		if (*head_pipe)
		{
			tmp_pipe = create_pipe(data);
			tmp_pipe->next = (*head_pipe)->next;
			tmp_pipe->src = str;
			(*head_pipe)->next = tmp_pipe;
		}
		else
		{
			*head_pipe = create_pipe(data);
			(*head_pipe)->src = ft_strdup(str);
		}
		ft_printf("PIPE-\n");
		print_pipe(*head_pipe);
		ft_printf("-----\n");
	}
	else
		return (-1);
	return (0);
}

void	free_last_gnl(t_gnl *tmp)
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

	ft_printf("\npipe :\n");
	print_pipe(head_pipe);
	ft_printf("\nroom :\n");
	print_room(head_room);
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
