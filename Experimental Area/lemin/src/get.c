/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 16:59:28 by adebray           #+#    #+#             */
/*   Updated: 2014/03/23 17:29:44 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			data_valid(t_data *data)
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

void		preget_room(t_data *data, t_room **head, char *str)
{
	t_room	*tmp;

	tmp = NULL;
	if (*head)
	{
		tmp = create_room();
		tmp->next = (*head)->next;
		tmp->str = get_room(str);
		(*head)->next = tmp;
	}
	else
	{
		*head = create_room();
		(*head)->str = get_room(str);
	}
	data->room_nb += 1;
}

void		init_head(t_data *data, t_pipe **head, char *str1, char *str2)
{
	*head = create_pipe(data);
	(*head)->src = str1;
	(*head)->dst[0] = create_pipe(data);
	(*head)->dst[0]->src = str2;
}

void		preget_pipe(t_data *data, t_pipe **head, char *str)
{
	int		i;
	char	*part_1;
	char	*part_2;
	t_pipe	*tmp;

	tmp = NULL;
	i = 0;
	while (str[i] != '-')
		i += 1;
	part_1 = ft_strsub(str, 0, i);
	part_2 = ft_strsub(str, i + 1, ft_strlen(str));
	if (*head)
	{
		tmp = get_pipe(*head, data, part_1);
		if (!tmp->src)
			tmp->src = part_1;
		i = 0;
		while (tmp->dst[i])
			i += 1;
		tmp->dst[i] = create_pipe(data);
		tmp->dst[i]->src = part_2;
	}
	else
		init_head(data, head, part_1, part_2);
}
