/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/15 12:03:45 by adebray          ###   ########.fr       */
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

int					*get_coord(t_gnl *head)
{
	int				*size;
	char			*curs;

	size = NULL;
	curs = head->str;
	size = malloc(sizeof(int) * 3);

	while (!ft_isdigit(*curs))
	{
		curs++;
	}
	size[0] = ft_atoi(curs);
	while(ft_isdigit(*curs))
		curs++;
	size[1] = ft_atoi(curs);
	size[2] = 0;
	return (size);
}

void				print_coord_fd(int *size, int *piece, int fd)
{
	ft_putendl_fd("<-->", fd);
	ft_putendl_fd(ft_itoa(size[0]), fd);
	ft_putendl_fd(ft_itoa(size[1]), fd);
	ft_putendl_fd(ft_itoa(piece[0]), fd);
	ft_putendl_fd(ft_itoa(piece[1]), fd);
}

void				ft_give_answer(void)
{
	ft_putendl("5 15");
	return ;
}

int					main(void)
{
	t_gnl			*head;
	t_gnl			*gnl;
	t_coord			*coord;
	int				fd;
	int				i;

	coord = malloc(sizeof(t_coord));

	fd = open("dump", O_CREAT | O_APPEND | O_WRONLY, 755);

	gnl = create();
	head = gnl;
	i = 0;
	while (get_next_line(0, &gnl->str))
	{
		if (SHEUM)
				ft_give_answer();
		if (!ft_strncmp(gnl->str, "Plateau", 7))
			coord->size = get_coord(gnl);
		else if (!ft_strncmp(gnl->str, "Piece", 5))
		{
			coord->piece = get_coord(gnl);
			i = coord->piece[0];
			print_coord_fd(coord->size, coord->piece, fd);
		}
		gnl->next = create();
		gnl = gnl->next;
	}

	gnl = head;
	while (gnl)
	{
		ft_putendl_fd(gnl->str, fd);
		gnl = gnl->next;
	}

	close (fd);
	return (0);
}
