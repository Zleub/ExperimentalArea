/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/03 04:22:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				main(int argc, char **argv)
{
	t_vars		*vars;
	char		*str;

	if (argc <= 2)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	vars = ft_initvars();
	str = ft_some_option(vars, argc, argv);
	if (str)
		return (1);
	ft_buildlist(vars, argc, argv);

	// ft_dumplist(vars->l_a);

	if (vars->i == 1)
		ft_interactive(vars, str);
	else
		ft_solve(vars);
	return (0);
}
