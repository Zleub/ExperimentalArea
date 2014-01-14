/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/14 19:59:57 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_gnl				*create(void)
{
	t_gnl			*elem;

	elem = malloc(sizeof(t_gnl));
	elem->str = NULL;
	elem->next = NULL;
	return (elem);
}

int					*get_size(t_gnl *head)
{
	int				*size;
	t_gnl			*curs;

	size = NULL;
	curs = head->next;
	size = malloc(sizeof(int) * 3);

	while (!ft_isdigit(*curs->str))
	{
		curs->str++;
	}
	size[0] = ft_atoi(curs->str);
	while(ft_isdigit(*curs->str))
		curs->str++;
	size[1] = ft_atoi(curs->str);
	size[2] = 0;
	return (size);
}

int					main(void)
{
	t_gnl			*head;
	t_gnl			*gnl;
	int				fd;

	gnl = create();
	head = gnl;
	while (get_next_line(0, &gnl->str) == 1 && gnl->str)
	{
		if (gnl->str[0] == '\0')
			close (0);
		gnl->next = create();
		gnl = gnl->next;
	}

	fd = open("dump", O_CREAT | O_TRUNC | O_WRONLY, 755);
	gnl = head;
	while (gnl)
	{
		ft_putendl_fd(gnl->str, fd);
		gnl = gnl->next;
	}
	// ft_putendl("5 15");

	int *size = get_size(head);

	while (*size)
	{
		ft_putendl_fd(ft_itoa(*size), fd);
		size++;
	}
	ft_putstr_fd("5 15", 1);



	close (fd);
	close (0);
	close (1);
	close (2);
	exit (0);
}
