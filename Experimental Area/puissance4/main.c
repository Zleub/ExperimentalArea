/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 22:35:44 by adebray           #+#    #+#             */
/*   Updated: 2014/03/12 04:57:23 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance.h>

void				print_array(t_pui4 *pui4)
{
	int				i;
	int				j;

	i = 0;
	while (i < pui4->y)
	{
		j = 0;
		while (j < pui4->x)
		{
			ft_printf("%c", pui4->array[i][j]);
			if (j < pui4->x - 1)
				ft_printf(" ");
			j += 1;
		}
		ft_printf("\n");
		i += 1;
	}
}

void				print_col(int x)
{
	int				j;

	j = 0;
	while (j < x)
	{
		ft_printf("\e[38;5;%um%d ", j / 10 + 1, j % 10);
		j += 1;
	}
	ft_printf("\e[39m\n");
}

char				**malloc_tab(int x, int y)
{
	int				i;
	char			**array;

	i = 0;
	array = (char**)malloc(sizeof(char*) * y + 1);
	while (i < y)
	{
		array[i] = (char*)malloc(sizeof(char) * x + 1);
		ft_memset(array[i], '.', x);
		i += 1;
	}
	// array[i] = NULL;
	return (array);
}

void				place_piece(int x, int player, t_pui4 *pui4)
{
	int				j;

	j = 0;
	while (j < pui4->y - 1 && pui4->array[j + 1][x] == '.')
		j += 1;
	if (player == 1)
		pui4->array[j][x] = 'O';
	else
		pui4->array[j][x] = 'X';

}

t_pui4				*create_pui4(void)
{
	t_pui4			*tmp;

	tmp = (t_pui4*)malloc(sizeof(t_pui4));
	tmp->x = -1;
	tmp->y = -1;
	tmp->ia = 0;
	tmp->player = 0;
	tmp->array = NULL;
	return (tmp);
}

void				get_rand(t_pui4 *pui4)
{
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		pui4->player = 1;
		pui4->ia = 2;
	}
	else
	{
		pui4->player = 2;
		pui4->ia = 1;
	}
}

int					ask_player(t_pui4 *pui4)
{
	int				x;
	char			*str;

	(void)pui4;
	if (get_next_line(0, &str) > 0)
	{
		if (ft_isdigit(str[0]))
		{
			x = ft_atoi(&str[0]);
			if (x > pui4->x - 1)
				return (-1);
			place_piece(x, pui4->player, pui4);
		}
		else
			return (-1);
	}
	return (0);
}

void				check_input(t_pui4 *pui4)
{
	if (ask_player(pui4) == -1)
	{
		ft_printf("False entry\n");
		check_input(pui4);
	}
}

int					check_case(int i, int j, t_pui4 *pui4)
{
	int				ret;
	int				m;
	int				n;

	ft_printf("check_case ARNO");
	m = n = -1;
	while (m < 2)
	{
		while (n < 2)
		{
			if (i + m > -1 && j + m > -1 && i + m < pui4->y && j + n < pui4->x && pui4->array[i + m][j + n] == pui4->array[i][j])
				ret = check_case(i + m, j + n, pui4);
			n += 1;
		}
		m += 1;
	}
	return (ret);
}

void				general_play(t_pui4 *pui4)
{
	int				i;
	int				j;
	int				tmp;

	ft_printf("general_play");
	i = 0;
	while (i < pui4->y)
	{
		j = 0;
		while (j < pui4->x)
		{
			ft_printf("general_play %d %d", i, j);
			if (pui4->array[i][j] != '.')
			{
				tmp = check_case(i, j, pui4);
				ft_printf("my ponderation is %d", tmp);
			}
			j += 1;
		}
		i += 1;
	}
}

void				game_round(t_pui4 *pui4)
{
	int				cmp;
	char			in_game;

	(void)pui4;
	if (pui4->ia == 1)
		cmp = 1;
	else
		cmp = 0;
	in_game = 0;
	while (in_game != -1)
	{
		cmp += 1;
		if (cmp % 2 == 0)
		{
			check_input(pui4);
			print_col(pui4->x);
			print_array(pui4);
		}
		else
			general_play(pui4);
	}
}

void				initial_play(t_pui4 *pui4)
{
	int				middle;

	middle = pui4->x / 2;
	place_piece(middle, pui4->ia, pui4);
}

void				game_start(t_pui4 *pui4)
{
	if (pui4->ia == 1)
	{
		initial_play(pui4);
		print_col(pui4->x);
		print_array(pui4);
	}
	else
	{
		print_col(pui4->x);
		print_array(pui4);
		check_input(pui4);
		print_col(pui4->x);
		print_array(pui4);
	}
	game_round(pui4);
}


int					main(int argc, char **argv)
{
	t_pui4			*pui4;

	pui4 = create_pui4();
	if (argc != 3)
	{
		ft_printf("Error");
		return (-1);
	}
	pui4->x = ft_atoi(argv[1]);
	pui4->y = ft_atoi(argv[2]);
	if (pui4->x < 7 || pui4->y < 6)
	{
		ft_printf("Error, grind too small (7x6 min)\n");
		return (-1);
	}

	ft_printf("%d x %d\n", pui4->x, pui4->y);

	pui4->array = malloc_tab(pui4->x, pui4->y);
	get_rand(pui4);
	ft_printf("player : %d, ia : %d\n", pui4->player, pui4->ia);
	game_start(pui4);
	return (0);
}
