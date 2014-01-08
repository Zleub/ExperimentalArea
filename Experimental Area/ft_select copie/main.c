/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/08 21:11:17 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	list = create();
	tmp = list;
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
		ft_printf("list : %p\n", list);
		ft_printf("\tstr : %s\n", list->str);
		ft_printf("\tslc : %d\n", list->slc);
		ft_printf("\tlen : %d\n", list->len);
		ft_printf("\tx : %d\n", list->x);
		ft_printf("\ty : %d\n", list->y);
		ft_printf("\tprev : %p\n", list->prev);
		ft_printf("\tnext : %p\n", list->next);
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
		ft_printf("list : %p\n", list);
		ft_printf("\theight : %d\n", list->height);
		ft_printf("\twidth : %d\n", list->width);
		ft_printf("\tcol_nb : %d\n", list->col_nb);
		ft_printf("\tcol_size : %d\n", list->col_size);
		ft_printf("\tli_nb : %d\n", list->li_nb);
		ft_printf("\tli_by_col : %d\n", list->li_by_col);
		ft_printf("\tcol : %p\n", list->col);
		ft_printf("\tprev : %p\n", list->prev);
		ft_printf("\tnext : %p\n", list->next);
		list = list->next;
		i += 1;
	}
}

// t_list				*is_key(t_list *list, char *read_char)
// {
// 	if (KEY_UP)
// 		return (list->prev);
// 	else if (KEY_DW)
// 		return (list->next);
// 	else
// 		return (list);
// }

// t_list				*is_spc(t_term *conf, t_list *list)
// {
// 	if (list->slc == 0)
// 		list->slc = 1;
// 	else
// 		list->slc = 0;
// 	so_printed(conf, list);
// 	return (list->next);
// }

// t_list					*read_user(t_term *conf, t_list *head)
// {
// 	char				read_char[4] = {0};
// 	t_list				*list;

// 	list = head;
// 	while (read_char[0] != 3 && (read_char[0] != 27 || read_char[1] != 0))
// 	{
// 		tputs(tgetstr("cl", NULL), 1, ft_putschar);
// 		so_printed(conf, head);
// 		tputs(tgoto(tgetstr("cm", NULL), list->x, list->y), 1, ft_putschar);
// 		ft_strclr(read_char);
// 		read(0, read_char, 3);
// 		list = is_key(list, read_char);
// 		if (read_char[0] == 32 && read_char[1] == 0)
// 			list = is_spc(conf, list);
// 		else if (read_char[0] == 10 && read_char[1] == 0)
// 			return (head);
// 		else if ((read_char[0] == 127 && read_char[1] == 0) || (read_char[0] == 126 && read_char[1] == 0))
// 			list->slc = -1;
// 		// else
// 		// 	ft_printf("%d.%d.%d.%d\n", read_char[0], read_char[1], read_char[2], read_char[3]);
// 	}
// 	return (head);
// }

t_term				*build_crown(t_list *head)
{
	t_term			*term;
	t_term			*tmp;
	t_list			*list;
	int				i;

	i = 0;
	term = init();
	tmp = term;
	list = head;
	while (list != head || i == 0)
	{
		if (list->y % tmp->height == 0)
		{
			tmp->col = list;
			tmp->col_nb = i;
			i += 1;
		}
		else if (list->next && (list->y + 1) % tmp->height == 0)
		{
			tmp->next = init();
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		list = list->next;
	}
	tmp->next = term;
	term->prev = tmp;
	return (term);
}

// void				so_printed(t_term *term, t_list *head)
// {
// 	t_list			*list;
// 	t_term			*tmp;
// 	int				i;

// 	i = 0;
// 	list = head;
// 	tmp = term;
// 	while (list != head || i == 0)
// 	{
// 		tputs(tgoto(tgetstr("cm", NULL), list->x, list->y), 1, ft_putschar);
// 		if (list->slc != -1)
// 		{
// 			if (list->slc == 1)
// 				tputs(tgetstr("mr", NULL), 1, ft_putschar);
// 			ft_printf(list->str);
// 			if (list->slc == 1)
// 				tputs(tgetstr("me", NULL), 1, ft_putschar);
// 		}
// 		i += 1;
// 		list = list->next;
// 	}
// }

int					main(int argc, char **argv)
{
	t_list			*list;
	t_term			*conf;

	tswitch(1);
	list = build_list(argc, argv);
	conf = build_crown(list);

	// so_printed(list);
	print_(conf);

	tswitch(0);
	return (0);
}