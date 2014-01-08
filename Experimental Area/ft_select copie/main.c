/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/08 14:11:07 by Arno             ###   ########.fr       */
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

t_list				*build_list(int argc, char **argv, t_term *conf)
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
		if (list->len > conf->maxlen)
			conf->maxlen = list->len;
		list->y = i - 1;
		conf->clist = i;
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
		reutrn (0);
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

int					main(int argc, char **argv)
{
	t_list			*list;
	t_term			*conf;

	tswitch(1);
	conf = init();
	list = build_list(argc, argv, conf);
	print(list);
	return (0);
}