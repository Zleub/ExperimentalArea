/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 20:19:34 by adebray           #+#    #+#             */
/*   Updated: 2013/12/24 20:22:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_printshackle(t_list *shackle)
{
	if (shackle)
	{
		ft_printf("shackle : %p\n", shackle);
		ft_printf("shackle->data : %d\n", shackle->data);
		ft_printf("shackle->next : %p\n", shackle->next);
	}
	else
		ft_printf("(no shackle)\n");
}

void			ft_dumplist(t_list **head)
{
	t_list		*tmp;

	if (!*head)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	tmp = *head;
	while (tmp)
	{
		ft_printshackle(tmp);
		tmp = tmp->next;
	}
}

static void			ft_printlist(t_list **head)
{
	t_list		*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_putendl_fd("", 1);
}

void			ft_print_la(t_vars *vars)
{
	ft_printf("l_a ");
	ft_printlist(vars->l_a);
}

void			ft_print_lb(t_vars *vars)
{
	ft_printf("l_b ");
	ft_printlist(vars->l_b);
}
