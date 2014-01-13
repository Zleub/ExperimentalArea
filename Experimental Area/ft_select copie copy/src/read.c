/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:27:35 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:06:59 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_list		*is_key(t_list *list, char *read_char)
{
	if (KEYUP)
		return (list->prev);
	else if (KEYDW)
		return (list->next);
	else
		return (list);
}

static t_list		*is_spc(t_list *list, char *read_char)
{
	if (read_char[0] == 32 && read_char[1] == 0)
	{
		if (list->slc == 0)
			list->slc = 1;
		else
			list->slc = 0;
		return (list->next);
	}
	else
		return (list);
}

int					read_user(t_list *head)
{
	char			read_char[4] = {0};

	while (42)
	{
		tputs(tgetstr("cl", NULL), 1, ft_putschar);
		so_printed(head);
		print_cursor(head);
		ft_strclr(read_char);
		read(0, read_char, 3);
		head = is_key(head, read_char);
		head = is_spc(head, read_char);
		if (read_char[0] == 10 && read_char[1] == 0)
			return (0);
		else if ((KEYDEL) || (KEYSUP))
		{
			head->slc = -1;
			head = head->next;
			if (head->next == head && head->slc == -1)
				return (-1);
		}
		else if (read_char[0] == 27 && read_char[1] == 0)
			return (-1);
	}
	return (0);
}
