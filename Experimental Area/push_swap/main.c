/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 10:39:17 by adebray          ###   ########.fr       */
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
		ft_printf(" ");
		l_b = *vars->l_b;
		if (l_b->next && l_b->data < l_b->next->data)
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
		}

	}
	if (l_a->next)
	{
		ft_ra(vars);
		ft_printf(" ");
		ft_solve(vars);
	}
	i = -1;
	while (*vars->l_b)
	{
		ft_pa(vars);
		if (*vars->l_b)
			ft_printf(" ");
	}
	if (i == -1)
		ft_printf("\n");
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
	str = ft_some_option(vars, argc, argv);
	if (str)
		return (1);
	ft_buildlist(vars, argc, argv);
	if (vars->i == 1)
		ft_interactive(vars, str);
	else
		ft_solve(vars);
	return (0);
}
