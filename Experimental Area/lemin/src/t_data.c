/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:05:59 by adebray           #+#    #+#             */
/*   Updated: 2014/03/23 16:45:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		get_lemin_nb(void)
{
	char	*tmp;
	int		i;

	i = 0;
	if (get_next_line(0, &tmp) > 0)
	{
		ft_printf("%s\n", tmp);
		if (tmp[0] == '#')
			i = get_lemin_nb();
		else if (tmp[9])
			i = 0;
		else if (tmp[0] == '-')
			i = 0;
		else
			i = ft_atoi(tmp);
	}
	return (i);
}

t_data	*create_data(void)
{
	t_data	*tmp;

	tmp = (t_data*)malloc(sizeof(t_data));
	tmp->start = NULL;
	tmp->end = NULL;
	tmp->room_nb = 0;
	tmp->lemin_nb = get_lemin_nb();
	return (tmp);
}

void	print_data(t_data *head)
{
	ft_printf("\tstart = %s\n", head->start);
	ft_printf("\tend = %s\n", head->end);
	ft_printf("\troom_nb = %d\n", head->room_nb);
	ft_printf("\tlemin_nb = %d\n", head->lemin_nb);
}
