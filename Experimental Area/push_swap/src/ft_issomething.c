/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issomething.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 20:33:27 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 10:37:55 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_isswap(t_vars *vars, char *str)
{
	if (SA)
	{
		ft_swap(vars->l_a);
		ft_print_la(vars);
	}
	else if (SB)
	{
		ft_swap(vars->l_b);
		ft_print_lb(vars);
	}
	else if (SS)
	{
		ft_swap(vars->l_a);
		ft_swap(vars->l_b);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else
		return ;
}

void			ft_ispush(t_vars *vars, char *str)
{
	if (PA)
	{
		ft_push(vars->l_a, vars->l_b);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else if (PB)
	{
		ft_push(vars->l_b, vars->l_a);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else
		return ;
}

void			ft_isreverse(t_vars *vars, char *str)
{
	if (RA)
	{
		ft_reverse(vars->l_a);
		ft_print_la(vars);
	}
	else if (RB)
	{
		ft_reverse(vars->l_b);
		ft_print_lb(vars);
	}
	else if (RR)
	{
		ft_reverse(vars->l_a);
		ft_reverse(vars->l_b);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else
		return ;
}

void			ft_isrreverse(t_vars *vars, char *str)
{
	if (RRA)
	{
		ft_rreverse(vars->l_a);
		ft_print_la(vars);
	}
	else if (RRB)
	{
		ft_rreverse(vars->l_b);
		ft_print_lb(vars);
	}
	else if (RRR)
	{
		ft_rreverse(vars->l_a);
		ft_rreverse(vars->l_b);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else
		return ;
}

void			ft_isprint(t_vars *vars, char *str)
{
	if (LA)
		ft_print_la(vars);
	else if (LB)
		ft_print_lb(vars);
	else if (LL)
	{
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else
		return ;
}
