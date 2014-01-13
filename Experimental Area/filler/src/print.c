/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:25:22 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:00:37 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void				print(t_list *head)
{
	int				i;
	t_list			*list;

	i = 0;
	list = head;
	while (list != head || i == 0)
	{
		ft_printf("\tlist : %p\n", list);
		ft_printf("\t\tstr : %s\n", list->str);
		ft_printf("\t\tslc : %d\n", list->slc);
		ft_printf("\t\tlen : %d\n", list->len);
		ft_printf("\t\tx : %d\n", list->x);
		ft_printf("\t\ty : %d\n", list->y);
		ft_printf("\t\tprev : %p\n", list->prev);
		ft_printf("\t\tnext : %p\n", list->next);
		list = list->next;
		i += 1;
	}
}

void				print_n(t_list *head, int n)
{
	int				i;
	t_list			*list;

	i = 0;
	list = head;
	while ((list != head || i == 0) && n--)
	{
		ft_printf("\tlist : %p\n", list);
		ft_printf("\t\tstr : %s\n", list->str);
		ft_printf("\t\tslc : %d\n", list->slc);
		ft_printf("\t\tlen : %d\n", list->len);
		ft_printf("\t\tx : %d\n", list->x);
		ft_printf("\t\ty : %d\n", list->y);
		ft_printf("\t\tprev : %p\n", list->prev);
		ft_printf("\t\tnext : %p\n", list->next);
		list = list->next;
		i += 1;
	}
}

void				print_(t_term *head)
{
	int				i;
	t_term			*list;

	i = 0;
	if (!head)
		return ;
	list = head;
	while (list != head || i == 0)
	{
		ft_printf("crown : %p\n", list);
		ft_printf("\theight : %d\n", list->height);
		ft_printf("\twidth : %d\n", list->width);
		ft_printf("\tcol_nb : %d\n", list->col_nb);
		ft_printf("\tcol_size : %d\n", list->col_size);
		ft_printf("\tli_nb : %d\n", list->li_nb);
		ft_printf("\tli_by_col : %d\n", list->li_by_col);
		ft_printf("\tcol : %p\n", list->col);
		print_n(list->col, list->li_nb);
		ft_printf("\tprev : %p\n", list->prev);
		ft_printf("\tnext : %p\n", list->next);
		list = list->next;
		i += 1;
	}
}

static void			walk_around(t_term *tmp)
{
	t_list			*list;
	int				i;
	int				n;

	i = 0;
	while (i + tmp->col_size < tmp->width - (tmp->col_nb - 1))
	{
		list = tmp->col;
		n = tmp->li_nb;
		while (n--)
		{
			tputs(tgoto(tgetstr("cm", NULL), XY), 1, ft_putschar);
			if (list->slc == 1)
				tputs(tgetstr("mr", NULL), 1, ft_putschar);
			ft_putstr_fd(list->str, isatty(STDOUT_FILENO));
			if (list->slc == 1)
				tputs(tgetstr("me", NULL), 1, ft_putschar);
			list = list->next;
		}
		i += tmp->col_size;
		tmp = tmp->next;
	}
}

t_list				*so_printed(t_list *head)
{
	static t_list	*_tmp;
	t_term			*term;
	int				i;

	i = 0;
	if (!head)
		term = build_crown(_tmp);
	else
	{
		_tmp = head;
		term = build_crown(head);
	}
	if (term == NULL)
		return (NULL);
	else
		walk_around(term);
	return (head);
}
