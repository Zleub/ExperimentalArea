/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/17 07:25:09 by adebray          ###   ########.fr       */
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
	char			*str;

	size = NULL;
	str = head->str;
	size = malloc(sizeof(int) * 3);

	while (!ft_isdigit(*str))
	{
		str++;
	}
	size[0] = ft_atoi(str);
	while(ft_isdigit(*str))
		str++;
	size[1] = ft_atoi(str);
	size[2] = 0;
	return (size);
}

void				print_dual_fd(int *size, int *piece, int fd)
{
	ft_putendl_fd("print_dualfd :", fd);
	ft_putendl_fd(ft_itoa(size[0]), fd);
	ft_putendl_fd(ft_itoa(size[1]), fd);
	ft_putendl_fd(ft_itoa(piece[0]), fd);
	ft_putendl_fd(ft_itoa(piece[1]), fd);
	ft_putendl_fd("print_dualfd end", fd);
}

void				print_piece_fd(char **tmp, int fd)
{
	while (*tmp)
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
	piece[j] = NULL;
	return (piece);
}

char					**get_plat(int *plateau_size)
{
	char				**plateau;
	char				*str;
	int					i;
	int					j;
	int					k;

	i = plateau_size[0];
	j = 0;
	plateau = malloc(sizeof(char*) * i + 1);
	while (i--)
	{
		get_next_line(0, &str);
		k = 0;
		while (ft_isdigit(str[k]))
			k += 1;
		plateau[j] = ft_strsub(str, k + 1, ft_strlen(str));
		j += 1;
	}
	plateau[j] = NULL;
	return (plateau);
}

void				truc_much(char **plateau, int fd)
{
	int				i;
	int				j;
	// char			**rectangle;

	i = j = 0;
	while (plateau[i] && plateau[i][j] != 'O')
	{
		j = 0;
		while (plateau[i][j] != 'O')
		{
			j += 1;
		}
		i += 1;
	}
	ft_putstr_fd("->", fd);
	ft_putstr_fd(ft_itoa(i), fd);
	ft_putstr_fd(" | ->", fd);
	ft_putstr_fd(ft_itoa(j), fd);
}

void				read_filler(t_gnl *gnl, t_dual *dual, int fd)
{
	char			**piece;
	char			**plateau;

	while (get_next_line(0, &gnl->str))
	{
		// piece = NULL;
		// plateau = NULL;
		if (!ft_strncmp(gnl->str, "Plateau", 7))
		{
			dual->size = get_dual(gnl);
			get_next_line(0, &gnl->str);
			free(gnl->str);
			plateau = get_plat(dual->size);
			print_piece_fd(plateau, fd);
		}
		else if (!ft_strncmp(gnl->str, "Piece", 5))
		{
			dual->piece = get_dual(gnl);
			print_dual_fd(dual->size, dual->piece, fd);
			piece = get_piece(dual->piece);
			print_piece_fd(piece, fd);
			ft_putendl_fd("<-->", fd);
			truc_much(plateau, fd);
			// ft_putendl_fd("13 33", 1);
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
	fd = open("dump", O_CREAT | O_TRUNC | O_WRONLY, 755);
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
