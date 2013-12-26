/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rreverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:58:15 by adebray           #+#    #+#             */
/*   Updated: 2013/12/25 23:44:59 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_rreverse(t_list **head)
{
	t_list		*_head;
	t_list		*tmp;

	if (!*head)
		return ;
	_head = *head;
	if (!_head->next)
		return ;
	while (_head->next->next)
		_head = _head->next;
	tmp = _head->next;
	_head->next = NULL;
	tmp->next = *head;
	*head = tmp;
}

void			ft_rra(t_vars *vars)
{
	ft_printf("%s", "rra\n");
	ft_rreverse(vars->l_a);
}

void			ft_rrb(t_vars *vars)
{
	ft_printf("%s", "rrb\n");
	ft_rreverse(vars->l_b);
}

void			ft_rrr(t_vars *vars)
{
	ft_printf("%s", "rrr\n");
	ft_rreverse(vars->l_b);
	ft_rreverse(vars->l_a);
}
