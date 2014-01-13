/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:18:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int							tswitch(int i)
{
	struct termios			term;
	static struct termios	save;

	if (i == 1)
	{
		if (tgetent(0, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		save = term;
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
		tcsetattr(0, 0, &term);
		return (0);
	}
	else
	{
		tcsetattr(0, 0, &save);
		return (0);
	}
}

void						print_cursor(t_list *head)
{
	static t_list			*tmp;

	if (!head)
	{
		tputs(tgoto(tgetstr("cm", NULL), tmp->x, tmp->y), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putschar);
		tputs(tgetstr("us", NULL), 1, ft_putschar);
		ft_putstr_fd(tmp->str, isatty(STDOUT_FILENO));
		tputs(tgetstr("ue", NULL), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("me", NULL), 1, ft_putschar);
	}
	else
	{
		tmp = head;
		tputs(tgoto(tgetstr("cm", NULL), tmp->x, tmp->y), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putschar);
		tputs(tgetstr("us", NULL), 1, ft_putschar);
		ft_putstr_fd(tmp->str, isatty(STDOUT_FILENO));
		tputs(tgetstr("ue", NULL), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("me", NULL), 1, ft_putschar);
	}
}

static void					print_result(t_list *head)
{
	int						i;
	int						j;
	t_list					*list;

	i = 1;
	j = 0;
	list = head;
	while (list != head || j == 0)
	{
		if (list->slc == 1)
		{
			if (i == 1)
			{
				ft_putstr_fd(list->str, 1);
				i -= 1;
			}
			else
			{
				ft_putstr_fd(" ", 1);
				ft_putstr_fd(list->str, 1);
			}
		}
		list = list->next;
		j += 1;
	}
}

int							main(int argc, char **argv)
{
	t_list					*list;

	if (tswitch(1) == -1 || argc < 2)
		return (0);
	list = build_list(argc, argv);
	_signal();
	tputs(tgetstr("ti", NULL), 1, ft_putschar);
	tputs(tgetstr("vi", NULL), 1, ft_putschar);
	if (read_user(list) == -1)
	{
		tputs(tgetstr("ve", NULL), 1, ft_putschar);
		tputs(tgetstr("te", NULL), 1, ft_putschar);
		tswitch(0);
		return (0);
	}
	tputs(tgetstr("ve", NULL), 1, ft_putschar);
	tputs(tgetstr("te", NULL), 1, ft_putschar);
	print_result(list);
	tswitch(0);
	return (0);
}
