/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:54:19 by adebray           #+#    #+#             */
/*   Updated: 2013/12/24 20:51:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void			ft_swap(t_list **head)
{
	t_list		*tmp;
	t_list		*start;

	if (!*head)
		return ;
	start = *head;
	if (start->next == NULL)
		return ;
	tmp = start->next;
	start->next = tmp->next;
	tmp->next = start;
	*head = tmp;
	return ;
}

void			ft_sa(t_vars *vars)
{
	ft_printf("%s", "sa\n");
	ft_swap(vars->l_a);
}

void			ft_sb(t_vars *vars)
{
	ft_printf("%s", "sb\n");
	ft_swap(vars->l_b);
}

void			ft_ss(t_vars *vars)
{
	ft_printf("%s", "ss\n");
	ft_swap(vars->l_a);
	ft_swap(vars->l_b);
}
