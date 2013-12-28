/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:57:02 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 10:34:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_reverse(t_list **head)
{
	t_list		*tmp;
	t_list		*_head;

	if (!*head)
		return ;
	tmp = *head;
	if (!tmp->next)
		return ;
	_head = *head;
	*head = tmp->next;
	while (_head->next)
		_head = _head->next;
	_head->next = tmp;
	tmp->next = NULL;
}

void			ft_ra(t_vars *vars)
{
	ft_printf("%s", "ra");
	ft_reverse(vars->l_a);
}

void			ft_rb(t_vars *vars)
{
	ft_printf("%s", "rb");
	ft_reverse(vars->l_b);
}

void			ft_rr(t_vars *vars)
{
	ft_printf("%s", "rr");
	ft_reverse(vars->l_b);
	ft_reverse(vars->l_a);
}
