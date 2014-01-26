/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:31:46 by adebray           #+#    #+#             */
/*   Updated: 2014/01/26 01:07:03 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int					*get_insc(t_dual *dual, char **map)
{
	int				*rectangle;
	int				*dual1;
	int				*dual2;

	rectangle = malloc(sizeof(int) * 5);
	dual1 = get_more(get_first(map), map);
	dual2 = get_less(dual1, get_second(map, dual->size), dual->size, map);
	rectangle[0] = dual1[0] - dual->piece[0] + 1;
	if (rectangle[0] <= 0)
		rectangle[0] = 0;
	rectangle[1] = dual1[1] - dual->piece[1] + 1;
	if (rectangle[1] <= 0)
		rectangle[1] = 0;
	rectangle[2] = dual2[0] + dual->piece[0] - 1;
	if (rectangle[2] >= dual->size[0])
		rectangle[2] = dual->size[0] - 1;
	rectangle[3] = dual2[1] + dual->piece[1] - 1;
	if (rectangle[3] >= dual->size[1])
		rectangle[3] = dual->size[1] - 1;
	rectangle[4] = 0;
	return (rectangle);
}

char				**get_array(int *rect, char **plateau)
{
	int				cmp[4] = {rect[0], 0, 0, 0};
	char			**array;

	array = malloc(sizeof(char*) * (rect[2] - rect[0] + 2));
	while (cmp[0] <= rect[2])
	{
		cmp[1] = rect[1];
		cmp[3] = 0;
		array[cmp[2]] = malloc(sizeof(char) * (rect[3] - rect[1] + 2));
		while (cmp[1] <= rect[3])
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

int					make_move(char **piece, char **array, int x, int y)
{
	int				cmp_array[5];

	cmp_array[0] = cmp_array[4] = 0;
	cmp_array[2] = x;
	while (piece[cmp_array[0]])
	{
		cmp_array[3] = y;
		cmp_array[1] = 0;
		while (PIECE_CHAR)
		{
			if (ARRAY_CHAR == 'O' && PIECE_CHAR == '*')
				cmp_array[4] += 1;
			else if ((ARRAY_CHAR == 'X' || ARRAY_CHAR == 'x')
						&& PIECE_CHAR == '*')
				return (0);
			cmp_array[3] += 1;
			cmp_array[1] += 1;
		}
		cmp_array[0] += 1;
		cmp_array[2] += 1;
	}
	if (cmp_array[4] == 1)
		return (1);
	else
		return (0);
}

void				free_array(char **array)
{
	int				k;

	k = 0;
	while (array[k])
		free(array[k++]);
	free(array);
}

void				give_answer(t_result *head, t_dual *duo, int *coor, int nbr)
{
	t_result		*result;
	int				i;

	i = 0;
	result = head;
	while (i < nbr / 2)
	{
		result = result->next;
		i += 1;
	}
	while ((result->y + coor[1] + duo->piece[1] > duo->size[1]
			|| result->x + coor[0] + duo->piece[0] > duo->size[0])
			&& result != result->next)
		result = result->next;
	ft_printf("%d %d\n", result->x + coor[0], result->y + coor[1]);
}
