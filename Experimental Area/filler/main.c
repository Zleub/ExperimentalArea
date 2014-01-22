/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/22 10:31:00 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <stdio.h>

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

int					*get_first(char **plateau)
{
	int				i;
	int				j;
	int				k;
	int				*dual;

	i = j = k = 0;
	dual = malloc(sizeof(int) * 3);
	while (plateau[i] && k == 0)
	{
		j = 0;
		while (plateau[i][j] && k == 0)
		{
			if (plateau[i][j] == 'O')
				k = 1;
			j += 1;
		}
		i += 1;
	}
	dual[0] = i - 2;
	dual[1] = j - 2;
	dual[2] = 0;
	return (dual);
}

int					*get_second(char **plateau, int *size)
{
	int				i;
	int				j;
	int				k;
	int				*dual;

	i = size[0] - 1;
	k = 0;
	dual = malloc(sizeof(int) * 3);
	while (plateau[i] && k == 0)
	{
		j = size[1] - 1;
		while (plateau[i][j] && k == 0)
		{
			// ft_putstr_fd("i -> ", 3);
			// ft_putnbr_fd(i, 3);
			// ft_putstr_fd(" . j -> ", 3);
			// ft_putnbr_fd(j, 3);
			// ft_putendl_fd("", 3);
			if (plateau[i][j] == 'O')
				k = 1;
			j -= 1;
		}
		i -= 1;
	}
	dual[0] = i + 2;
	dual[1] = j + 2;
	dual[2] = 0;
	return (dual);
}


int					*get_more(int *first_dual, char** plateau)
{
	int				*actual_dual;
	int				stop;

	actual_dual = malloc(sizeof(int) * 3);
	actual_dual[0] = first_dual[0];
	stop = 0;
	while (plateau[actual_dual[0]])
	{
		actual_dual[1] = 0;
		while (plateau[actual_dual[0]][actual_dual[1]])
		{
			if (plateau[actual_dual[0]][actual_dual[1]] == 'O' && actual_dual[1] - 1 < first_dual[1])
				first_dual[1] = actual_dual[1] - 1;
			actual_dual[1] += 1;
		}
		actual_dual[0] += 1;
	}

	return (first_dual);
}

int					*get_less(int *first_dual, int *second_dual, int *size, char **plateau)
{
	int				*actual_dual;
	int				stop;

	actual_dual = malloc(sizeof(int) * 3);
	actual_dual[0] = second_dual[0];
	stop = 0;
	while (actual_dual[0] >= first_dual[0] && plateau[actual_dual[0]])
	{
		actual_dual[1] = size[1] - 1;
		while (actual_dual[1] >= first_dual[1] && plateau[actual_dual[0]][actual_dual[1]])
		{
			if (plateau[actual_dual[0]][actual_dual[1]] == 'O' && actual_dual[1] + 1 > second_dual[1])
				second_dual[1] = actual_dual[1] + 1;
			actual_dual[1] -= 1;
		}
		actual_dual[0] -= 1;
	}

	return (second_dual);
}

int					*get_insc(t_dual *dual, char **plateau)
{
	int				*rectangle;
	int				*first_dual;
	int				*second_dual;

	rectangle = malloc(sizeof(int) * 5);
	first_dual = get_more(get_first(plateau), plateau);
	second_dual = get_less(first_dual, get_second(plateau, dual->size), dual->size, plateau);

	rectangle[0] = first_dual[0] - dual->piece[0] + 1;
	rectangle[1] = first_dual[1] - dual->piece[1] + 1;
	rectangle[2] = second_dual[0] + dual->piece[0] - 1;
	rectangle[3] = second_dual[1] + dual->piece[1] - 1;
	rectangle[4] = 0;
	return (rectangle);
}

char				**get_array(int *rectangle, char **plateau)
{
	int				cmp[4] = {rectangle[0], 0, 0, 0};
	char			**array;

	array = malloc(sizeof(char*) * (rectangle[2] - rectangle[0] + 2));
	while (cmp[0] <= rectangle[2])
	{
		cmp[1] = rectangle[1];
		cmp[3] = 0;
		array[cmp[2]] = malloc(sizeof(char) * (rectangle[3] - rectangle[1] + 2));
		while (cmp[1] <= rectangle[3])
		{
			array[cmp[2]][cmp[3]] = plateau[cmp[0]][cmp[1]];
			cmp[3] += 1;
			cmp[1] += 1;
		}
		array[cmp[2]][cmp[3]] = '\0';
		cmp[2] += 1;
		cmp[0] += 1;
	}
	array[cmp[2]] = NULL;
	return (array);
}

int				make_move(char **piece, char **array, int x, int y)
{
	int				piece_x;
	int				piece_y;
	int				plat_x;
	int				plat_y;
	int				cmp;

	piece_x = 0;
	plat_x = x;
	cmp = 0;
	while (piece[piece_x])
	{
		plat_y = y;
		piece_y = 0;
		while (piece[piece_x][piece_y])
		{
			if (array[plat_x][plat_y] == 'O' && piece[piece_x][piece_y] != '.')
			{
				array[plat_x][plat_y] = 'O';
				cmp += 1;
				if (cmp > 1)
					return (0);
			}
			else if (piece[piece_x][piece_y] != '.')
				array[plat_x][plat_y] = 'O';
			plat_y += 1;
			piece_y += 1;
		}
		piece_x += 1;
		plat_x += 1;
	}
	if (cmp == 1)
		return (1);
	else
		return (0);
}

void				print_array(char **array)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			dprintf(3, "%c", array[i][j]);
			j += 1;
		}
		ft_putendl_fd("", 3);
		i += 1;
	}
	ft_putendl_fd("", 3);
}

void				truc_much(t_dual *dual, char **plateau, char **piece)
{
	int				i;
	int				j;
	int				nbr;
	int				*rectangle;
	char			**array;
	t_result		*head;
	t_result		*result;

	rectangle = get_insc(dual, plateau);
	i = 0;
	j = 0;
	nbr = 0;
	dprintf(3, "?? %d ??\n", rectangle[2] - rectangle[0] + 2 - dual->piece[0]);
	dprintf(3, "?? %d ??\n", rectangle[3] - rectangle[1] + 2 - dual->piece[1]);

	result = malloc(sizeof(t_result));
	head = result;
	while (i < rectangle[2] - rectangle[0] + 2 - dual->piece[0])
	{
		j = 0;
		while (j < rectangle[3] - rectangle[1] + 2 - dual->piece[1])
		{
			array = get_array(rectangle, plateau);
			if (make_move(piece, array, i, j))
			{
				dprintf(3, "make move[%d][%d]\n", i, j);
				print_array(array);
				result->x = i;
				result->y = j;
				result->next = malloc(sizeof(t_result));
				result = result->next;
				result->x = -1;
				result->y = -1;
				nbr += 1;
			}
			j += 1;
		}
		i += 1;
	}

	i = 0;
	j = 0;
	if (nbr % 2 == 0)
	{
		nbr /= 2;
	}
	else
	{
		nbr = nbr / 2 + 1;
	}

	result = head;
	while (i < nbr)
	{
		// dprintf(3, "%d,%d / %d\n", result->x, result->y, nbr);
		result = result->next;
		i += 1;
	}
	sleep (1);
	ft_printf("%d %d\n", result->x + rectangle[0], result->y + rectangle[1]);
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
			truc_much(dual, plateau, piece);
			// ft_putendl_fd("8 14", 1);
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
