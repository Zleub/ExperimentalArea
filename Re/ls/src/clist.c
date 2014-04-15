/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 18:08:25 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 18:30:56 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_clist			*create_clist(void)
{
	t_clist		*tmp;

	tmp = (t_clist*)malloc(sizeof(t_clist));
	tmp->tmp = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void			print_clist(t_clist *head, t_global *global)
{
	if (global->a != 1 && head->tmp[0] == '.')
		;
	else
		ft_printf("%s\n", head->tmp);
	if (head->next)
		print_clist(head->next, global);
}

void			print_rclist(t_clist *head, t_global *global)
{
	while (head->next)
		head = head->next;
	while (head)
	{
		if (global->a != 1 && head->tmp[0] == '.')
			;
		else
			ft_printf("%s\n", head->tmp);
		head = head->prev;
	}
}

t_clist			*add_elem_clist(t_clist *tclist, char *str)
{
	tclist->tmp = ft_strdup(str);
	tclist->next = create_clist();
	tclist->next->prev = tclist;
	tclist = tclist->next;
	return (tclist);
}
