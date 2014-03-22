/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:07:41 by adebray           #+#    #+#             */
/*   Updated: 2014/03/21 12:49:12 by adebray          ###   ########.fr       */
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
	int	i;

	i = 0;
	while (head)
	{
		ft_printf("head : %p -> '%s'\n", head, head->src);
		if (head->dst[i])
		{
			while (head->dst[i])
			{
				ft_printf("dst[%d] : %p -> '%s'\n", i, head->dst[i], head->dst[i]->src);

			// 	print_pipe(head->dst[i]);
				i += 1;
			}
		}
		head = head->next;
		i = 0;
	}
}
