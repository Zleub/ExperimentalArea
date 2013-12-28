/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 21:00:39 by adebray           #+#    #+#             */
/*   Updated: 2013/12/25 03:24:21 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list			*ft_initshackle(void)
{
	t_list		*shackle;

	shackle = malloc(sizeof(t_list));
	if (!shackle)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	shackle->data = 0;
	shackle->next = NULL;
	return (shackle);
}

t_vars			*ft_initvars(void)
{
	t_vars		*vars;

	vars = malloc(sizeof(t_vars*));
	vars->l_a = malloc(sizeof(t_list**));
	vars->l_b = malloc(sizeof(t_list**));
	vars->i = 0;
	vars->max = -2147483648;
	return (vars);
}

void			ft_buildlist(t_vars *vars, int argc, char **argv)
{
	t_list		*shackle;
	int			i;

	i = 1;
	if (vars->i)
		i = 2;
	shackle = ft_initshackle();
	*vars->l_a = shackle;
	while (i < argc)
	{
		shackle->data = ft_atoi(argv[i]);
		if (shackle->data > vars->max)
			vars->max = shackle->data;
		if (i < argc - 1)
			shackle->next = ft_initshackle();
		shackle = shackle->next;
		i += 1;
	}
	return ;
}
