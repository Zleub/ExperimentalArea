/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 03:43:26 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 20:41:53 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_global		*create_global(void)
{
	t_global	*new_global;

	new_global = (t_global*)malloc(sizeof(t_global));
	new_global->nb_dir = -1;
	new_global->a = -1;
	new_global->t = -1;
	new_global->r = -1;
	return (new_global);
}

void			print_global(t_global *new_global)
{
	ft_printf("nb_dir: %d\n", new_global->nb_dir);
	ft_printf("a: %d\n", new_global->a);
	ft_printf("t: %d\n", new_global->t);
	ft_printf("r: %d\n", new_global->r);
}

void			custom_error(char *dir, int check)
{
	if (errno == 20)
		ft_printf("%s ", dir);
	else if (errno == 13)
	{
		if (check == 1)
			ft_printf("%s:\nls: %s: Permission denied\n", dir, dir);
		else
			ft_printf("ls: %s: Permission denied\n", dir, dir);
	}
}

void			illegal_argument(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
	ft_printf(" [file ...]\n");
	exit (0);
}
