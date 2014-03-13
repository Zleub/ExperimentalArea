/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:05:27 by adebray           #+#    #+#             */
/*   Updated: 2014/03/13 13:16:28 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_gnl	*create_gnl(void)
{
	t_gnl	*tmp;

	tmp = (t_gnl*)malloc(sizeof(t_gnl));
	tmp->str = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	print_gnl(t_gnl *head)
{
	ft_printf("\t%s\n", head->str);
	if (head->next)
		print_gnl(head->next);
}
