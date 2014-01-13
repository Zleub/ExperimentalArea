/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crown.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:27:27 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 17:56:36 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_term		*init(void)
{
	t_term			*conf;

	conf = malloc(sizeof(t_term));
	conf->height = tgetnum("li");
	conf->width = tgetnum("co");
	conf->col_nb = 0;
	conf->col_size = 0;
	conf->li_nb = 0;
	conf->li_by_col = 0;
	conf->next = NULL;
	conf->prev = NULL;
	return (conf);
}

static t_list		*check_not(t_list *list)
{
	if (list->next == list && list->slc == -1)
		return (NULL);
	else if (list->slc == -1)
	{
		list->prev->next = list->next;
		list->next->prev = list->prev;
		return (list->next);
	}
	else
		return (list);
}

static t_term		*check_col(t_term *tmp, t_list *list, int k)
{
	int				i;

	i = 0;
	if (k % tmp->height == 0)
	{
		tmp->col = list;
		tmp->col_nb = i;
		i += 1;
	}
	if (ft_strlen(list->str) > (size_t)tmp->col_size)
		tmp->col_size = ft_strlen(list->str);
	tmp->li_nb += 1;
	if ((k + 1) % tmp->height == 0)
	{
		tmp->next = init();
		tmp->next->prev = tmp;
		return (tmp->next);
	}
	else
		return (tmp);
}

t_term				*build_crown(t_list *head)
{
	t_term			*term;
	t_term			*tmp;
	t_list			*list;
	int				i;
	int				j;

	i = 0;
	j = 0;
	term = init();
	tmp = term;
	list = head;
	while (list != head || i == 0)
	{
		check_not(list);
		if (tmp->prev && (i) % tmp->height == 0)
			j += tmp->prev->col_size + 1;
		list->x = j;
		tmp = check_col(tmp, list, i);
		list->y = i % tmp->height;
		i += 1;
		list = list->next;
	}
	tmp->next = term;
	term->prev = tmp;
	return (term);
}
