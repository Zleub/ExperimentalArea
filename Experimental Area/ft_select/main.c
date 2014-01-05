/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/04 23:38:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_list				*create(void)
{
	t_list			*list;

	list = malloc(sizeof(t_list));
	list->str = NULL;
	list->len = 0;
	list->x = 0;
	list->y = 0;
	list->next = NULL;
	return (list);
}

t_list				*build(int argc, char **argv, t_term *conf)
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
			list->next = create();
		list = list->next;
		i += 1;
	}
	return (tmp);
}

void				print(t_list *list)
{
	while (list)
	{
		ft_printf("list : %p\n", list);
		ft_printf("\tstr : %s\n", list->str);
		ft_printf("\tlen : %d\n", list->len);
		ft_printf("\tx : %d\n", list->x);
		ft_printf("\ty : %d\n", list->y);
		list = list->next;
	}
}

int						tswitch(void)
{
	char				buffer[2048];
	struct termios		term;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ICANON;
	term.c_lflag &= ECHO;
	term.c_lflag &= NOFLSH;
	// term.c_lflag &= ISIG;
	tcsetattr(0, 0, &term);
	return (0);
}

int					main(int argc, char **argv)
{
	t_list			*list;
	t_term			*conf;

	conf = malloc(sizeof(t_term));

	// print(list);

	tswitch();

	conf->height = tgetnum("li");
	conf->width = tgetnum("co");
	conf->maxlen = -2147483648;
	conf->clist = 0;
	conf->maxlin = 1;
	list = build(argc, argv, conf);

	// ft_printf("got %d list line against %d term line\n", conf->clist, conf->height);


	if (conf->clist > conf->height)
		conf->maxlin += conf->clist / conf->height;

	// ft_printf("i need %d columns\n", conf->maxlin);

	// ft_printf("i need %d columns\n", (conf->clist / conf->height) + 1);
	// ft_printf("maxlen : %d\n", conf->maxlen);
	// ft_printf("width : %d\n", conf->width);

	if (conf->width % (conf->maxlen + 1) == 3)
		conf->maxcol = (conf->width / (conf->maxlen + 1) + 1);
	else
		conf->maxcol = conf->width / (conf->maxlen + 1);

	// ft_printf("so i can make %d word cols\n", conf->maxcol);

	if (conf->maxlin > conf->maxcol)
	{
		ft_printf("NIQUE");
		return (-1);
	}

	t_list	**head;

	head = malloc(sizeof(t_list*));
	*head = list;
	tputs(tgetstr("ti", NULL), 1, ft_putschar);

	int i = 0;
	while (list)
	{
		tputs(tgoto(tgetstr("cm", NULL), list->x, list->y), 1, ft_putschar);
		ft_printf(list->str);
		list = list->next;
		if (list && list->y >= conf->height)
		{
			if (list->y != 0 && list->y % conf->height == 0)
				i += conf->maxlen + 1;
			list->x += i;
			list->y %= conf->height;
			// list->y = list->y - 1;
		}
	}
	// print(*head);
	char				read_char[4] = {0};

	// tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putschar);
	while (read_char[0] != 3)
	{
		print(list);
		ft_strclr(read_char);
		read(0, read_char, 3);
		// ft_printf("%d\n", ft_atoi(read_char));
		// ft_printf("%s\n", read_char);
		if (read_char[0] == 10)
			print(list);
	}
	tputs(tgetstr("te", NULL), 1, ft_putschar);


	return (0);
}
