/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:44:35 by adebray           #+#    #+#             */
/*   Updated: 2014/01/26 01:10:06 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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
	if (dual[0] < 0)
		dual[0] = 0;
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
			if (plateau[actual_dual[0]][actual_dual[1]] == 'O'
					&& actual_dual[1] - 1 < first_dual[1])
				first_dual[1] = actual_dual[1] - 1;
			actual_dual[1] += 1;
		}
		actual_dual[0] += 1;
	}
	return (first_dual);
}

int					*get_less(int *dual_1, int *dual_2, int *size, char **map)
{
	int				*actual_dual;
	int				stop;

	actual_dual = malloc(sizeof(int) * 3);
	actual_dual[0] = dual_2[0] - 1;
	stop = 0;
	while (actual_dual[0] >= dual_1[0] && map[actual_dual[0]])
	{
		actual_dual[1] = size[1] - 1;
		while (actual_dual[1] >= dual_1[1]
				&& map[actual_dual[0]][actual_dual[1]])
		{
			if (map[actual_dual[0]][actual_dual[1]] == 'O'
					&& actual_dual[1] + 1 > dual_2[1])
			{
				dual_2[1] = actual_dual[1] + 1;
			}
			actual_dual[1] -= 1;
		}
		actual_dual[0] -= 1;
	}
	return (dual_2);
}
