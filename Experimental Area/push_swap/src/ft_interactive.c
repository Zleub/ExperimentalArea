/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 20:27:15 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 09:40:29 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <gnl.h>

char			*ft_some_option(t_vars *vars, int argc, char **argv)
{
	if (ft_isdigit(argv[1][0]) || ft_isdigit(argv[1][1]))
		return (NULL);
	else if (argc <= 2)
	{
		ft_printf("Usage: push_swap [-i] [list]\n");
		return ("you got it wrong");
	}
	else if (argv[1][0] != '-')
	{
		ft_printf("Illegal option : %s\n", argv[1]);
		ft_printf("Usage: push_swap [-i] [list]\n");
		return ("you got it wrong");
	}
	else if (argv[1][1] != 'i')
	{
		ft_printf("Illegal option : %s\n", argv[1]);
		ft_printf("Usage: push_swap [-i] [list]\n");
		return ("you got it wrong");
	}
	else
	{
		ft_printf("Yeah, some interactive option is on !\n");
		vars->i = 1;
		return (NULL);
	}
}

void			ft_interactive(t_vars *vars, char *str)
{
	ft_print_la(vars);
	ft_print_lb(vars);
	while(!str || str[0] != 'q')
	{
		ft_printf("-> ");
		get_next_line(0, &str);
		ft_isswap(vars, str);
		ft_ispush(vars, str);
		ft_isreverse(vars, str);
		ft_isrreverse(vars, str);
		ft_isprint(vars, str);
		if (str[0] != 'q')
		{
			free(str);
			str = NULL;
		}
	}
}
