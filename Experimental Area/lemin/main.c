/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/23 17:37:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_gnl	*do_gnl(t_gnl *tmp, t_data *data, t_room *head_room, t_pipe *head_pipe)
{
	ft_printf("%s\n", tmp->str);
	if (*tmp->str == '\0')
	{
		free_last_gnl(tmp);
		return (NULL);
	}
	if (fill_data(tmp->str, data, &head_room, &head_pipe) == -1)
	{
		ft_printf("data error\n");
		return (NULL);
	}
	tmp->next = create_gnl();
	tmp->next->prev = tmp;
	return (tmp->next);
}

void	print_end(t_data *data, t_room *head_path)
{
	int		i;
	int		j;

	i = data->lemin_nb;
	j = 0;
	while (head_path)
	{
		ft_printf("L%d-%s", j, head_path->str);
		head_path = head_path->next;
		i -= 1;
	}
}

int		fill_gnl(t_gnl **head, t_data *data)
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
		tmp = do_gnl(tmp, data, head_room, head_pipe);
	}
	free_last_gnl(tmp);
	head_path = get_path(data, head_pipe);
	print_room(head_room);
	print_pipe(head_pipe);
	print_data(data);
	if (head_path)
	{
		print_end(data, head_path);
		return (0);
	}
	else
		return (-1);
}

void	get_lemin(void)
{
	t_data	*data;
	t_gnl	*head;

	data = create_data();
	if (fill_gnl(&head, data) == -1)
	{
		ft_printf("NO PATH\n");
		return ;
	}
}

int		main(void)
{
	get_lemin();
	return (0);
}
