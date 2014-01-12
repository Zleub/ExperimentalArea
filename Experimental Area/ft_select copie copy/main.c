/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 08:24:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include <ft_select.h>

t_list				*create(void)
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

t_term				*init(void)
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
		term.c_lflag &= ICANON;
		term.c_lflag &= ECHO;
		tcsetattr(0, 0, &term);
		return (0);
	}
	else
	{
		tcsetattr(0, 0, &save);
		return (0);
	}
}

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

t_term				*build_crown(t_list *head)
{
	t_term			*term;
	t_term			*tmp;
	t_list			*list;
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	term = init();
	tmp = term;
	list = head;
	while (list != head || i == 0)
	{
		if (list->next == list && list->slc == -1)
			return (NULL);
		if (list->slc == -1)
		{
			list->prev->next = list->next;
			list->next->prev = list->prev;
			list = list->next;
		}
		else
		{
			if (k % tmp->height == 0)
			{
				tmp->col = list;
				tmp->col_nb = i;
				i += 1;
			}
			if (ft_strlen(list->str) > (size_t)tmp->col_size)
				tmp->col_size = ft_strlen(list->str);
			tmp->li_nb += 1;
			list->x = j;
			if (list->next && (k + 1) % tmp->height == 0)
			{
				j += tmp->col_size + 1;
				tmp->next = init();
				tmp->next->prev = tmp;
				tmp = tmp->next;
			}
			list->y = k % tmp->height;
			k += 1;
			list = list->next;
		}
	}
	tmp->next = term;
	term->prev = tmp;
	return (term);
}

t_list				*so_printed(t_list *head)
{
	static t_list			*_tmp;
	t_list					*list;
	t_term					*tmp;
	t_term					*term;
	int						i;
	int						n;

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
	tmp = term;
	while (i + tmp->col_size < tmp->width - (tmp->col_nb - 1))
	{
		list = tmp->col;
		n = tmp->li_nb;
		while (n--)
		{
			tputs(tgoto(tgetstr("cm", NULL), list->x, list->y % tmp->height), 1, ft_putschar);

			if (list->slc == 1)
				tputs(tgetstr("mr", NULL), 1, ft_putschar);

			ft_printf("%s", list->str);

			if (list->slc == 1)
				tputs(tgetstr("me", NULL), 1, ft_putschar);
			list = list->next;
		}
		i += tmp->col_size;
		tmp = tmp->next;
	}
	free(term);
	term = NULL;
	return (head);
}

void					print_cursor(t_list *head)
{
	static t_list		*tmp;

	if (!head)
	{
		tputs(tgoto(tgetstr("cm", NULL), tmp->x, tmp->y), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putschar);
		tputs(tgetstr("us", NULL), 1, ft_putschar);
		ft_printf(tmp->str);
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
		ft_printf(tmp->str);
		tputs(tgetstr("ue", NULL), 1, ft_putschar);
		if (tmp->slc == 1)
			tputs(tgetstr("me", NULL), 1, ft_putschar);
	}
}

t_list				*is_key(t_list *list, char *read_char)
{
	if (KEY_UP)
		return (list->prev);
	else if (KEY_DW)
		return (list->next);
	else
		return (list);
}

t_list				*is_spc(t_list *list, char *read_char)
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

// t_list				*is_del(t_list *list, char *read_char)
// {
// 	else if ((read_char[0] == 127 && read_char[1] == 0) || (read_char[0] == 126 && read_char[1] == 0))
// 	{
// 		list->slc = -1;
// 		tputs(tgetstr("cl", NULL), 1, ft_putschar);
// 		if (list->y == 0 && list->x == 0)
// 			head = so_printed(head->next);
// 		else
// 			head = so_printed(head);
// 		if (head == NULL)
// 			return (NULL);
// 		list = list->next;
// 	}
// }

t_list					*read_user(t_list *head)
{
	char				read_char[4] = {0};
	t_list				*list;

	list = head;
	while (42)
	{
		tputs(tgetstr("cl", NULL), 1, ft_putschar);
		so_printed(list);

		print_cursor(list);

		ft_strclr(read_char);
		read(0, read_char, 3);
		list = is_key(list, read_char);
		list = is_spc(list, read_char);
		if (read_char[0] == 10 && read_char[1] == 0)
			return (head);
		else if ((read_char[0] == 127 && read_char[1] == 0) || (read_char[0] == 126 && read_char[1] == 0))
		{
			list->slc = -1;
			// tputs(tgetstr("cl", NULL), 1, ft_putschar);
			// if (list->y == 0 && list->x == 0)
			// 	head = so_printed(head->next);
			// else
			// 	head = so_printed(head);
			// if (head == NULL)
			// 	return (NULL);
			list = list->next;
		}
		else if (read_char[0] == 3 || (read_char[0] == 27 && read_char[1] == 0))
			return(head);
	}
	return (head);
}

void				print_result(t_list *head)
{
	int					i;
	int					j;
	t_list				*list;

	i = 1;
	j = 0;
	list = head;
	while (list != head || j == 0)
	{
		if (list->slc == 1)
		{
			if (i == 1)
			{
				ft_printf(list->str);
				i -= 1;
			}
			else
			{
				ft_printf(" ");
				ft_printf(list->str);
			}
		}
		list = list->next;
		j += 1;
	}
}

void				resize(int sig)
{
	sig = sig;
	tgetent(0, getenv("TERM"));
	tputs(tgetstr("cl", NULL), 1, ft_putschar);
	so_printed(NULL);
	print_cursor(NULL);
}

void				_signal(void)
{
	void (*array[1])(int) = {resize};

	signal(SIGWINCH, array[SIG_WINCH]);
}

int					main(int argc, char **argv)
{
	t_list			*list;

	if (tswitch(1) == -1)
		return (0);
	list = build_list(argc, argv);
	_signal();
	tputs(tgetstr("ti", NULL), 1, ft_putschar);
	tputs(tgetstr("vi", NULL), 1, ft_putschar);
	read_user(list);
	tputs(tgetstr("ve", NULL), 1, ft_putschar);
	tputs(tgetstr("te", NULL), 1, ft_putschar);
	tswitch(0);
	// print_result(list);
	return (0);
}
