/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:31:46 by adebray           #+#    #+#             */
/*   Updated: 2014/01/25 12:32:00 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int					*get_insc(t_dual *dual, char **plateau)
{
	int				*rectangle;
	int				*first_dual;
	int				*second_dual;

	rectangle = malloc(sizeof(int) * 5);
	first_dual = get_more(get_first(plateau), plateau);
	second_dual = get_less(first_dual, get_second(plateau, dual->size), dual->size, plateau);
	rectangle[0] = first_dual[0] - dual->piece[0] + 1;
	if (rectangle[0] <= 0)
		rectangle[0] = 0;
	rectangle[1] = first_dual[1] - dual->piece[1] + 1;
	if (rectangle[1] <= 0)
		rectangle[1] = 0;
	rectangle[2] = second_dual[0] + dual->piece[0] - 1;
	if (rectangle[2] >= dual->size[0])
		rectangle[2] = dual->size[0] - 1;
	rectangle[3] = second_dual[1] + dual->piece[1] - 1;
	if (rectangle[3] >= dual->size[1])
		rectangle[3] = dual->size[1] - 1;
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
	int				cmp_array[5];

	cmp_array[0] = cmp_array[4] = 0;
	cmp_array[2] = x;
	while (piece[cmp_array[0]])
	{
		cmp_array[3] = y;
		cmp_array[1] = 0;
		while (piece[cmp_array[0]][cmp_array[1]])
		{
			if (array[cmp_array[2]][cmp_array[3]] == 'O' && piece[cmp_array[0]][cmp_array[1]] == '*')
				cmp_array[4] += 1;
			else if ((array[cmp_array[2]][cmp_array[3]] == 'X' || array[cmp_array[2]][cmp_array[3]] == 'x') && piece[cmp_array[0]][cmp_array[1]] == '*')
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
