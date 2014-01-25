/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/25 12:32:03 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_result			*build_result(t_result *result, int *nbr, int i, int j)
{
	result->x = i;
	result->y = j;
	result->next = malloc(sizeof(t_result));
	result = result->next;
	*nbr += 1;
	return (result);
}

void				truc_much(t_dual *dual, char **plateau, char **piece)
{
	int				cmp[3];
	int				*rectangle;
	char			**array;
	t_result		*head;
	t_result		*result;

	rectangle = get_insc(dual, plateau);
	cmp[0] = cmp[1] = cmp[2] = 0;
	head = result = malloc(sizeof(t_result));
	while (cmp[0] < rectangle[2] - rectangle[0] + 2 - dual->piece[0])
	{
		cmp[1] = 0;
		while (cmp[1] < rectangle[3] - rectangle[1] + 2 - dual->piece[1])
		{
			result->x = result->y = -1;
			array = get_array(rectangle, plateau);
			if (make_move(piece, array, cmp[0], cmp[1]))
				result = build_result(result, &cmp[2], cmp[0], cmp[1]);
			free_array(array);
			cmp[1] += 1;
		}
		cmp[0] += 1;
	}
	result->next = head;
	give_answer(head, dual, rectangle, cmp[2]);
}

void				read_filler(t_gnl *gnl, t_dual *dual)
{
	char			**piece;
	char			**plateau;

	while (get_next_line(0, &gnl->str))
	{
		if (!ft_strncmp(gnl->str, "Plateau", 7))
		{
			dual->size = get_dual(gnl);
			get_next_line(0, &gnl->str);
			free(gnl->str);
			plateau = get_plat(dual->size);
		}
		else if (!ft_strncmp(gnl->str, "Piece", 5))
		{
			dual->piece = get_dual(gnl);
			piece = get_piece(dual->piece);
			truc_much(dual, plateau, piece);
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

	dual = malloc(sizeof(t_dual));
	head = create();
	read_filler(head, dual);
	return (0);
}
