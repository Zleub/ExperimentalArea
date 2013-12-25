/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/25 08:18:35 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_solve(t_vars *vars)
{
	t_list		*l_a;

	l_a = *vars->l_a;

	while (l_a->data != vars->max)
	{
		l_a = l_a->next;
		ft_pb(vars);
	}
	if (!l_a->next)
	{
		while ()
	}

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
