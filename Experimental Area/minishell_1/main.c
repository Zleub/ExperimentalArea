/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/28 12:34:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>
#include <ft_printf.h>

void		build_bin(t_vars *vars, char **environ;)
{

}

int			main(void)
{
	char			*str;
	extern char		**environ;
	t_vars			*vars;

	vars = malloc(sizeof(t_vars));
	build_bin(vars, environ);
	while (!str || str[0] != 'q')
	{
		ft_printf("-> ");
		if (get_next_line(0, &str) > 0)
		{
			ft_printf("%s\n", str);
			if (str[0] != 'q')
			{
				free(str);
				str = NULL;
			}
		}
	}
	return (0);
}
