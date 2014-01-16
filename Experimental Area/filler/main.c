/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/16 12:04:20 by Arno             ###   ########.fr       */
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

int					*get_dual(t_gnl *head)
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

void				print_dual_fd(int *size, int *piece, int fd)
{
	ft_putendl_fd("<-->", fd);
	ft_putendl_fd(ft_itoa(size[0]), fd);
	ft_putendl_fd(ft_itoa(size[1]), fd);
	ft_putendl_fd(ft_itoa(piece[0]), fd);
	ft_putendl_fd(ft_itoa(piece[1]), fd);
}

void				print_piece_fd(char **tmp, int i, int fd)
{
	while (i--)
	{
		ft_putendl_fd(*tmp, fd);
		tmp++;
	}
}

void				give_answer(void)
{
	ft_putendl("5 15");
	return ;
}

char					**get_piece(int *piece_size)
{
	char				**piece;
	int					i;
	int					j;

	i = piece_size[0];
	j = 0;
	piece = malloc(sizeof(char*) * i + 1);
	while (i--)
	{
		get_next_line(0, &piece[j]);
		j += 1;
	}
	piece[j] = "\0";
	return (piece);
}

char					**get_plat(int *plateau_size, char *str1)
{
	char				**plateau;
	int					i;
	int					j;

	i = plateau_size[0];
	j = 1;
	plateau = malloc(sizeof(char*) * i + 1);
	plateau[0] = str1;
	while (i--)
	{
		get_next_line(0, &plateau[j]);
		j += 1;
	}
	plateau[j] = "\0";
	return (plateau);
}

void				read_filler(t_gnl *gnl, t_dual *dual, int fd)
{
	char			**tmp;
	char			**plateau;

	while (get_next_line(0, &gnl->str))
	{
		tmp = NULL;
		plateau = NULL;
		if (!ft_strncmp(gnl->str, "Plateau", 7))
			dual->size = get_dual(gnl);
		else if (!ft_strncmp(gnl->str, "Piece", 5))
		{
			dual->piece = get_dual(gnl);
			ft_putnbr_fd(dual->piece[0], 2);
			print_dual_fd(dual->size, dual->piece, fd);
			tmp = get_piece(dual->piece);
			print_piece_fd(tmp, dual->piece[0], fd);
		}
		else if (ft_isdigit(gnl->str[0]) && ft_isdigit(gnl->str[1]) && ft_isdigit(gnl->str[2]))
		{
			plateau = get_plat(dual->size, gnl->str);
			// print_piece_fd(plateau, dual->size[0], fd);
		}
		else
		{
			gnl->next = create();
			gnl = gnl->next;
		}
	}
}

int					main(void)
{
	t_gnl			*head;
	t_dual			*dual;

	int				fd;

	dual = malloc(sizeof(t_dual));

	fd = open("dump", O_CREAT | O_APPEND | O_WRONLY, 755);

	head = create();
	read_filler(head, dual, fd);

	t_gnl			*tmp;

	tmp = head;
	ft_putendl_fd("DUMP :", fd);
	while (tmp)
	{
		ft_putendl_fd(tmp->str, fd);
		tmp = tmp->next;
	}

	close (fd);
	return (0);
}
