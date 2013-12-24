/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issomething.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 20:33:27 by adebray           #+#    #+#             */
/*   Updated: 2013/12/24 20:50:56 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_isswap(t_vars *vars, char *str)
{
	if (SA)
	{
		ft_sa(vars);
		ft_print_la(vars);
	}
	else if (SB)
	{
		ft_sb(vars);
		ft_print_lb(vars);
	}
	else if (SS)
	{
		ft_ss(vars);
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
		ft_pa(vars);
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	else if (PB)
	{
		ft_pb(vars);
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
		ft_ra(vars);
		ft_print_la(vars);
	}
	else if (RB)
	{
		ft_rb(vars);
		ft_print_lb(vars);
	}
	else if (RR)
	{
		ft_rr(vars);
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
		ft_rra(vars);
		ft_print_la(vars);
	}
	else if (RRB)
	{
		ft_rrb(vars);
		ft_print_lb(vars);
	}
	else if (RRR)
	{
		ft_rrr(vars);
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
