/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:07:41 by adebray           #+#    #+#             */
/*   Updated: 2014/03/13 14:24:14 by adebray          ###   ########.fr       */
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
	tmp->src = NULL;
	tmp->dst = (t_pipe**)malloc(sizeof(t_pipe*) * data->room_nb);
	while (i < data->room_nb)
	{
		tmp->dst[i] = NULL;
		i += 1;
	}
	return (tmp);
}

void	print_pipe(t_pipe *head, int c)
{
	int		i;
	int		j;

	i = 0;
	j = c + 1;
	if (head)
	{
		j = c;
		while (j--)
			ft_printf("\t");
		ft_printf("• head : %p -> '%s'\n", head, head->src);
		if (head->dst)
		{
			while (head->dst[i])
			{
				j = c + 1;
				while (j--)
					ft_printf("\t");
				ft_printf("-> child %d : %p -> '%s'\n",i,  head->dst[i], head->dst[i]->src);
				print_pipe(head->dst[i], c + 1);
				i += 1;
			}
		}
	}
}
