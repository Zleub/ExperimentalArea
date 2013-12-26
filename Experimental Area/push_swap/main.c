/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 07:16:02 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		l_b = *vars->l_b;
		tmp = l_b;
		while (tmp->next)
			tmp = tmp->next;
		if (l_b->next && l_b->data < l_b->next->data)
		{
			if (!l_b->next->next)
				ft_sb(vars);
			else if (l_b->next->next && l_b->data > l_b->next->next->data)
				ft_sb(vars);
			else
			{
				i = 1;
				while (l_b->next->next && l_b->data < l_b->next->next->data)
				{
					i += 1;
					ft_printf("while (l_b->next->next && l_b->data '%d' < l_b->next->next->data) '%d'\n", l_b->data, l_b->next->next->data);
					ft_print_la(vars);
					ft_print_lb(vars);


						// tmp = *vars->l_b;
						// while (tmp->next)
						// 	tmp = tmp->next;
					if (l_b->data > tmp->data)
					{
						ft_printf("rrb + sb if l_b->data : %d > %d : tmp->data\n", l_b->data, tmp->data);
						ft_rrb(vars);
						ft_sb(vars);
					}
					else
					{
												ft_printf("rb if l_b->data : %d < %d : tmp->data\n", l_b->data, tmp->data);
						ft_rb(vars);
					}
						// 			tmp = l_b;
						// while (tmp->next)
						// 	tmp = tmp->next;
					// WORK TO DO NOT TO RRB RB IN VAIN
					ft_print_la(vars);
					ft_print_lb(vars);
				}
				while (i != 0)
				{
					ft_rb(vars);
					i -= 1;
				}
			}
		}
		ft_print_la(vars);
		ft_print_lb(vars);
	}
	if (l_a->next)
	{
		ft_ra(vars);
		ft_solve(vars);
	}
	while (*vars->l_b)
		ft_pa(vars);
	ft_print_la(vars);
	ft_print_lb(vars);
}

int				main(int argc, char **argv)
{
	t_vars		*vars;
	char		*str;

	if (argc <= 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	vars = ft_initvars();
	str = ft_some_option(vars, argv);
	if (str)
		return (1);
	ft_buildlist(vars, argc, argv);
	if (vars->i == 1)
		ft_interactive(vars, str);
	else
		ft_solve(vars);
	return (0);
}
