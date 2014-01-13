/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:25:13 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 17:56:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_list		*create(void)
{
	t_list			*list;

	list = malloc(sizeof(t_list));
	list->str = NULL;
	list->slc = 0;
	list->len = 0;
	list->x = 0;
	list->y = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_list				*build_list(int argc, char **argv)
{
	int				i;
	t_list			*list;
	t_list			*tmp;

	i = 1;
	tmp = list = create();
	while (i < argc)
	{
		list->str = argv[i];
		list->len = ft_strlen(argv[i]);
		list->y = i - 1;
		if (i < argc - 1)
		{
			list->next = create();
			list->next->prev = list;
		}
		else
		{
			tmp->prev = list;
			list->next = tmp;
		}
		list = list->next;
		i += 1;
	}
	return (tmp);
}
