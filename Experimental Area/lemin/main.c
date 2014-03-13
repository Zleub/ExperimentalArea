/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/13 15:07:58 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_pipe	*get_pipe(char *str, t_pipe *head)
{
	int		i;

	ft_printf("get_pipe : %s\n", str);
	if (head)
	{
		i = 0;
		ft_printf("%s vs %s\n", head->src, str);
		if (!ft_strcmp(head->src, str))
			return (head);
		else
		{
			if (head->dst)
			{
				while (head->dst[i])
				{
					ft_printf("check up %d\n", i);
					return (get_pipe(str, head->dst[i]));
					i += 1;
				}
			}
		}
	}
	return (NULL);
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
	else if (is_room(str))
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
	}
	else if (is_pipe(str))
	{
		ft_printf("-----\n");
		print_pipe(*head_pipe, 0);
		ft_printf("-----\n");
		if (*head_pipe)
		{
			char *part_1;
			char *part_2;

			i = 0;
			while (str[i] != '-')
				i += 1;
			part_1 = ft_strsub(str, 0, i);
			tmp_pipe = get_pipe(part_1, *head_pipe);
			if (!tmp_pipe)
			{
				ft_printf("1. tmp_pipe is NULL\n");
				exit (0);
			}

			if (tmp_pipe->dst)
			{
				if (tmp_pipe->dst[0])
				{
					int j = 0;
					while (tmp_pipe->dst[j])
						j += 1;
					tmp_pipe->dst[j] = create_pipe(data);
					tmp_pipe->dst[j]->src = ft_strsub(str, i + 1, ft_strlen(str));
				}
				else
				{
					tmp_pipe->dst[0] = create_pipe(data);
					tmp_pipe->dst[0]->src = ft_strsub(str, i + 1, ft_strlen(str));
				}
			}

			ft_printf("%p\n", tmp_pipe);

			part_2 = ft_strsub(str, i + 1, ft_strlen(str));

			// ft_printf("part_1 : '%s' part_2 : '%s'\n", part_1, part_2);
			// if (tmp_pipe)
			// 	ft_printf("tmp_pipe->src : %s\n", tmp_pipe->src);
			// else
			// 	ft_printf("2. tmp_pipe is NULL\n");

		}
		else
		{
			tmp_pipe = create_pipe(data);
			*head_pipe = tmp_pipe;
			i = 0;
			while (str[i] != '-')
				i += 1;
			tmp_pipe->src = ft_strsub(str, 0, i);
			tmp_pipe->dst[0] = create_pipe(data);
			tmp_pipe->dst[0]->src = ft_strsub(str, i + 1, ft_strlen(str));
		}
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
