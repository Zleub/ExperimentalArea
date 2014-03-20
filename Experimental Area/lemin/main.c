/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/20 16:22:35 by adebray          ###   ########.fr       */
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

void	fill_data(char *str, t_data *data, t_room **head_room, t_pipe **head_pipe)
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
		ft_printf("%s\n", str);
		// ft_printf("-----\n");
		// print_pipe(*head_pipe, 0);
		// ft_printf("-----\n");
	}
	else
		ft_printf("else -> %s\n", str);
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
		fill_data(tmp->str, data, &head_room, &head_pipe);
		tmp->next = create_gnl();
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	free_last_gnl(tmp);

	ft_printf("\npipe :\n");
	print_pipe(head_pipe, 0);
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
