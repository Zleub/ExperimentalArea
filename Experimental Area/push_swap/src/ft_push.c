/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:56:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 10:34:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_push(t_list **dst, t_list **src)
{
	t_list		*tmp;
	t_list		*_tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	_tmp = *dst;
	*dst = tmp;
	tmp->next = _tmp;
}

void			ft_pb(t_vars *vars)
{
	ft_printf("%s", "pb");
	ft_push(vars->l_b, vars->l_a);
}

void			ft_pa(t_vars *vars)
{
	ft_printf("%s", "pa");
	ft_push(vars->l_a, vars->l_b);
}
