/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/03/02 16:58:31 by Arno             ###   ########.fr       */
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

void	print_gnl(t_gnl *head)
{
	ft_printf("\t%s\n", head->str);
	if (head->next)
		print_gnl(head->next);
}

void	print_data(t_data *head)
{
	ft_printf("\tstart = %s\n", head->start);
	ft_printf("\tend = %s\n", head->end);
	ft_printf("\troom_nb = %d\n", head->room_nb);
	ft_printf("\tlemin_nb = %d\n", head->lemin_nb);
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

void	fill_data(char *str, t_data *data)
{
	char	*tmp;

	if (str[0] == '#' && str[1] != '#')
		;
	else if (str[0] == '#' && str[1] == '#')
	{
		if (!ft_strcmp(&str[2], "start"))
		{
			if (get_next_line(0, &tmp) > 0)
				data->start = get_room(tmp);
			data->room_nb += 1;
		}
		else if (!ft_strcmp(&str[2], "end"))
		{
			if (get_next_line(0, &tmp) > 0)
				data->end = get_room(tmp);
			data->room_nb += 1;
		}
	}
	else if (is_room(str))
		data->room_nb += 1;
	else
		ft_printf("-> %s\n", str);
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

	tmp = create_gnl();
	*head = tmp;
	while (get_next_line(0, &tmp->str) > 0)
	{
		if (*tmp->str == '\0')
		{
			free_last_gnl(tmp);
			return ;
		}
		fill_data(tmp->str, data);
		tmp->next = create_gnl();
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	free_last_gnl(tmp);
}

void	get_lemin(void)
{
	t_data	*data;
	t_gnl	*head;

	data = create_data();
	fill_gnl(&head, data);
	// check_data(data);

	ft_printf("\nThis is after parse dump thing\n");
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
