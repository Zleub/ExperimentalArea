/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/11 15:11:24 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_gnl	*create_gnl(void)
{
	t_gnl	*tmp;

	tmp = (t_gnl*)malloc(sizeof(t_gnl));
	tmp->str = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	print_gnl(t_gnl *head)
{
	ft_printf("\t%s\n", head->str);
	if (head->next)
		print_gnl(head->next);
}

int		get_lemin_nb(void)
{
	char	*tmp;
	int		i;

	i = 0;
	if (get_next_line(0, &tmp) > 0)
	{
		if (tmp[0] == '#')
			i = get_lemin_nb();
		else
			i = ft_atoi(tmp);
	}
	return (i);
}

t_data	*create_data(void)
{
	t_data	*tmp;

	tmp = (t_data*)malloc(sizeof(t_data));
	tmp->start = NULL;
	tmp->end = NULL;
	tmp->room_nb = 0;
	tmp->lemin_nb = get_lemin_nb();
	return (tmp);
}

void	print_data(t_data *head)
{
	ft_printf("\tstart = %s\n", head->start);
	ft_printf("\tend = %s\n", head->end);
	ft_printf("\troom_nb = %d\n", head->room_nb);
	ft_printf("\tlemin_nb = %d\n", head->lemin_nb);
}

t_room	*create_room(void)
{
	t_room *tmp;

	tmp = (t_room*)malloc(sizeof(t_room));
	tmp->str = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	print_room(t_room *head)
{
	if (head)
	{
		ft_printf("\t'%s'\n", head->str);
		if (head->next)
			print_room(head->next);
	}
}

t_pipe	*create_pipe(void)
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	tmp = (t_pipe*)malloc(sizeof(t_pipe));
	tmp->src = NULL;
	tmp->dst = NULL;
	// tmp->dst = (t_pipe**)malloc(sizeof(t_pipe*) * data->room_nb);
	// while (tmp->dst[i])
	// {
	// 	ft_printf("ft_checkup i : %d\n", i);
	// 	tmp->dst[i] = NULL;
	// 	i += 1;
	// }
	return (tmp);
}

void	print_pipe(t_pipe *head)
{
	int		i;

	i = 0;
	if (head)
	{
		ft_printf("head : %p -> '%s'\n", head, head->src);
		if (head->dst)
		{
			while (head->dst[i])
			{
				ft_printf("child %d : %p -> '%s'\n",i,  head->dst[i], head->dst[i]->src);
				// print_pipe(head->dst[i]);
				i += 1;
			}
		}
	}
}

int		is_room(char *str)
{
	int			j;
	int			i;

	i = j = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			if (i == 0)
				j -= 1;
			while (ft_isspace(str[i]))
			{
				i += 1;
				if (str[i] == '\0')
					j -= 1;
			}
			j += 1;
		}
		i += 1;
	}
	if (j == 2)
		return (1);
	else
		return (0);
}

int		is_pipe(char *str)
{
	int		i;
	int		j;

	i = j= 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			while (ft_isspace(str[i]))
				i += 1;
		}
		if (str[i] == '-' && str[i - 1] && str[i + 1])
			j += 1;
		i += 1;
	}
	return (j);
}

char	*get_room(char *tmp)
{
	int		i;
	int		j;

	i = j = 0;
	while (ft_isspace(tmp[i]))
		i += 1;
	j = i;
	while (!ft_isspace(tmp[i]))
		i += 1;
	tmp[i] = '\0';
	return (ft_strdup(&tmp[j]));
}

void	start_end(char *str, t_data *data, t_room **head)
{
	t_room	*room_tmp;
	char	*char_tmp;

	if (!ft_strcmp(&str[2], "start"))
	{
		if (get_next_line(0, &char_tmp) > 0)
			data->start = get_room(char_tmp);
		data->room_nb += 1;

/* build t_room list */
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
	else if (!ft_strcmp(&str[2], "end"))
	{
		if (get_next_line(0, &char_tmp) > 0)
			data->end = get_room(char_tmp);
		data->room_nb += 1;

/* build t_room list */
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
}

void		search_room(char *str, t_data *data, t_pipe *head)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, head->src, ft_strlen(head->src)))
	{
	ft_printf("ft_strncmp(str '%s', head->src '%s', ft_strlen(head->src)) '%d'\n", str, head->src, ft_strlen(head->src));

		if (head->dst)
		{
			while (head->dst[i])
			{
				search_room(str, data, head->dst[i]);
				i += 1;
			}
		}
	}
	else
	{
		ft_printf("else\nHere i am : &str[i] = '%s' && head->src = '%s'\n", &str[i], head->src);
		if (head->dst)
		{
			ft_printf("if head->dst\n");
		}
		else
		{
			head->dst = (t_pipe**)malloc(sizeof(t_pipe*) * data->room_nb);
			i = 0;
			while (head->dst[i])
			{
				ft_printf("while heaed->dst[i]\n");
				// head->dst[i] = create_pipe();
				i += 1;
			}
		}
	}
}

void		get_pipe(char *str, t_data *data, t_pipe **head)
{
	int		i;
	int		j;

	ft_printf("get_pipe\nstr = %s, %d\n", str, data->room_nb);
		ft_printf("DUMP\n");
	print_pipe(*head);
	ft_printf("\n\n");
	if (*head)
	{
		i = 0;
		while (ft_isspace(str[i]))
		{
			i += 1;
		}
		search_room(&str[i], data, *head);

	}
	else
	{
		i = ft_strlen(str) - 1;
		*head = create_pipe();
		(*head)->dst = (t_pipe**)malloc(sizeof(t_pipe*) * data->room_nb);
		if ((*head)->dst == NULL)
			ft_printf("head->dst NULL\n");
		j = 0;
		while ((*head)->dst[j])
		{
			ft_printf("check j = %d\n", j);
			(*head)->dst[j] = create_pipe();
			j += 1;
		}
		ft_printf("check 2 '%s' vs '%s'\n", (*head)->dst[0]->src, &str[i]);
		while (str[i] != '-')
			i -= 1;
		(*head)->dst[0]->src = ft_strdup(&str[i + 1]);
		str[i] = '\0';
		ft_printf("check 3 '%s' vs '%s'\n", (*head)->dst[0]->src, str);
		while (!ft_isspace(str[i]) && i >= 0)
		{
			i -= 1;
		}
		(*head)->src = ft_strdup(&str[i + 1]);
		ft_printf("check 4 '%s'\n", (*head)->src);
	}

}

void	fill_data(char *str, t_data *data, t_room **head_room, t_pipe **head_pipe)
{
	t_room *tmp;

	if (str[0] == '#' && str[1] != '#')
		;
	else if (str[0] == '#' && str[1] == '#')
		start_end(str, data, &(*head_room));
	else if (is_room(str))
	{
		if (*head_room)
		{
			tmp = create_room();
			tmp->next = (*head_room)->next;
			tmp->str = get_room(str);
			(*head_room)->next = tmp;
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
		get_pipe(str, data, head_pipe);
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
	// check_data(data);

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
