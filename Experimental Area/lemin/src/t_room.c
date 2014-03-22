/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:06:40 by adebray           #+#    #+#             */
/*   Updated: 2014/03/21 14:35:34 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char	*get_room(char *tmp)
{
	int		i;
	int		j;

	i = j = 0;
	while (ft_isspace(tmp[i]))
		i += 1;
	j = i;
	while (!ft_isspace(tmp[i]))
		i += 1;
	tmp[i] = '\0';
	return (ft_strdup(&tmp[j]));
}

t_room	*create_room(void)
{
	t_room *tmp;

	tmp = (t_room*)malloc(sizeof(t_room));
	tmp->str = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	print_room(t_room *head)
{
	if (head)
	{
		ft_printf("\t'%s'\n", head->str);
		if (head->next)
			print_room(head->next);
	}
}
