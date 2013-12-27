/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shity_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 02:45:43 by adebray           #+#    #+#             */
/*   Updated: 2013/12/27 02:46:24 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_reverso(t_vars *vars, t_list *l_b, t_list *tmp, int i)
{
	while (l_b->data > tmp->data)
	{
		i += 1;
		if (l_b->data > tmp->data)
		{
			ft_rrb(vars);
			ft_printf(" ");
			ft_sb(vars);
			ft_printf(" ");
		}
		else
		{
			ft_rb(vars);
			ft_printf(" ");
		}
		tmp = *vars->l_b;
		while (tmp->next)
			tmp = tmp->next;
	}
	while (i != 0)
	{
		ft_rb(vars);
		ft_printf(" ");
		i -= 1;
	}
}

void			ft_postmax(t_vars *vars, t_list *l_a, int i)
{
	if (l_a->next)
	{
		ft_ra(vars);
		ft_printf(" ");
		ft_solve(vars);
		i = -1;
	}
	while (*vars->l_b)
	{
		ft_pa(vars);
		if (*vars->l_b)
			ft_printf(" ");
	}
	if (i == -1)
	{
		ft_printf("\n");
		ft_print_la(vars);
	}
}

void			ft_bswap(t_vars *vars, t_list *l_b, t_list *tmp, int i)
{
	if (!l_b->next->next)
	{
		ft_sb(vars);
		ft_printf(" ");
	}
	else if (l_b->next->next && l_b->data > l_b->next->next->data)
	{
		ft_sb(vars);
		ft_printf(" ");
	}
	else
	{
		i = 1;
		tmp = *vars->l_b;
		while (tmp->next)
			tmp = tmp->next;
		ft_reverso(vars, l_b, tmp, i);
	}
}

void			ft_solve(t_vars *vars)
{
	t_list		*l_a;
	t_list		*l_b;
	t_list		*tmp;
	int			i;

	l_a = *vars->l_a;
	while (l_a->data != vars->max)
	{
		l_a = l_a->next;
		ft_pb(vars);
		ft_printf(" ");
		l_b = *vars->l_b;
		if (l_b->next && l_b->data < l_b->next->data)
		{
			ft_bswap(vars, l_b, tmp, i);
		}
	}
	ft_postmax(vars, l_a, i);
}
