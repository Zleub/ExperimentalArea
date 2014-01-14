/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/14 08:40:30 by adebray          ###   ########.fr       */
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

int					main(void)
{
	t_gnl			*head;
	t_gnl			*gnl;
	// int				fd;

	gnl = create();
	head = gnl;
	while (get_next_line(0, &gnl->str) == 1)
	{
		gnl->next = create();
		gnl = gnl->next;
	}

	// fd = open("dump", O_CREAT | O_WRONLY, 755);
	// gnl = head;
	// while (gnl)
	// {
	// 	ft_putendl_fd(gnl->str, fd);
	// 	gnl = gnl->next;
	// }

	// close (fd);
	ft_putstr("5 5");

	return (0);
}
