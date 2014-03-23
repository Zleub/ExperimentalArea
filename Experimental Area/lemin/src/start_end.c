/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:39:50 by adebray           #+#    #+#             */
/*   Updated: 2014/03/23 12:25:00 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	get_start(t_data *data, t_room **head, t_room *room_tmp)
{
	char	*char_tmp;

	if (get_next_line(0, &char_tmp) > 0)
	{
		ft_printf("%s\n", char_tmp);
		if (char_tmp[0] == '#')
			get_start(data, head, room_tmp);
		else
			data->start = get_room(char_tmp);
	}
	data->room_nb += 1;
	if (*head)
	{
		room_tmp = create_room();
		room_tmp->str = ft_strdup(data->start);
		room_tmp->next = *head;
		*head = room_tmp;
	}
	else
	{
		*head = create_room();
		(*head)->str = ft_strdup(data->start);
	}
}

void	get_end(t_data *data, t_room **head, t_room *room_tmp)
{
	char	*char_tmp;

	if (get_next_line(0, &char_tmp) > 0)
	{
		ft_printf("%s\n", char_tmp);
		if (char_tmp[0] == '#')
			get_end(data, head, room_tmp);
		else
			data->end = get_room(char_tmp);
	}
	data->room_nb += 1;
	if (*head)
	{
		room_tmp = *head;
		while (room_tmp->next)
			room_tmp = room_tmp->next;
		room_tmp->next = create_room();
		room_tmp = room_tmp->next;
		room_tmp->str = ft_strdup(data->end);
	}
	else
	{
		*head = create_room();
		(*head)->str = ft_strdup(data->end);
	}
}

void	start_end(char *str, t_data *data, t_room **head)
{
	t_room	*room_tmp;

	room_tmp = NULL;
	if (!ft_strcmp(str, "##start"))
	{
		get_start(data, head, room_tmp);
	}
	else if (!ft_strcmp(str, "##end"))
	{
		get_end(data, head, room_tmp);
	}
}
