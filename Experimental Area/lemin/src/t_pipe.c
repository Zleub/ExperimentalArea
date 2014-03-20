/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:07:41 by adebray           #+#    #+#             */
/*   Updated: 2014/03/20 21:19:08 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_pipe	*create_pipe(t_data *data)
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	tmp = (t_pipe*)malloc(sizeof(t_pipe));
	tmp->src = NULL;
	tmp->dst = (t_pipe**)malloc(sizeof(t_pipe*) * data->room_nb);
	while (i < data->room_nb)
	{
		tmp->dst[i] = NULL;
		i += 1;
	}
	tmp->next = NULL;
	return (tmp);
}

void	print_pipe(t_pipe *head)
{
	if (head)
	{
		ft_printf("head : %p -> '%s'\n", head, head->src);
		if (head->dst[0])
		{
			// ft_printf("dst[0] : %p -> '%s'\n", head->dst[0], head->dst[0]->src);
			print_pipe(head->dst[0]);
		}
		if (head->next)
		{
			// ft_printf("-> next : %p -> '%s'\n", head->next, head->next->src);
			print_pipe(head->next);
		}
	}
}
