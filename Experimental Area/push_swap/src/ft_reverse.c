/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:57:02 by adebray           #+#    #+#             */
/*   Updated: 2013/12/24 20:51:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void			ft_reverse(t_list **head)
{
	t_list		*tmp;
	t_list		*_head;

	if (!*head)
		return ;
	tmp = *head;
	_head = *head;
	*head = tmp->next;
	while (_head->next)
		_head = _head->next;
	_head->next = tmp;
	tmp->next = NULL;
}

void			ft_ra(t_vars *vars)
{
	ft_printf("%s", "ra\n");
	ft_reverse(vars->l_a);
}

void			ft_rb(t_vars *vars)
{
	ft_printf("%s", "rb\n");
	ft_reverse(vars->l_b);
}

void			ft_rr(t_vars *vars)
{
	ft_printf("%s", "rr\n");
	ft_reverse(vars->l_b);
	ft_reverse(vars->l_a);
}
