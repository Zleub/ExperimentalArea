/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/24 10:18:01 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ft_printf.h>

#include <stdlib.h>

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

void			ft_dumplist(t_list **head)
{
	t_list		*tmp;

	if (!head)
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

void			ft_printlist(t_list **head)
{
	t_list		*tmp;

	if (!head)
	{
		ft_putendl_fd("(null)", 2);
		return ;
	}
	tmp = *head;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_putendl_fd("", 1);
}


void			ft_buildlist(t_list **head, int argc, char **argv)
{
	t_list		*shackle;
	int			i;

	i = 1;
	shackle = ft_initshackle();
	*head = shackle;
	while (i < argc)
	{
		shackle->data = ft_atoi(argv[i]);
		if (i < argc - 1)
			shackle->next = ft_initshackle();
		shackle = shackle->next;
		i += 1;
	}
	return ;
}

void			ft_swap(t_list **head)
{
	t_list		*tmp;
	t_list		*start;

	start = *head;
	tmp = start->next;
	start->next = tmp->next;
	tmp->next = start;
	*head = tmp;
	return ;
}

void			ft_push(t_list **dst, t_list **src)
{
	t_list		*tmp;
	t_list		*_tmp;

	tmp = *src;
	*src = tmp->next;
	_tmp = *dst;
	*dst = tmp;
	tmp->next = _tmp;
}

void			ft_sa(t_list **l_a)
{
	ft_printf("%s", "sa\n");
	ft_swap(l_a);
}

void			ft_sb(t_list **l_b)
{
	ft_printf("%s", "sb\n");
	ft_swap(l_b);
}

void			ft_ss(t_list **l_a, t_list **l_b)
{
	ft_printf("%s", "ss\n");
	ft_swap(l_a);
	ft_swap(l_b);
}

void			ft_pa(t_list **l_a, t_list **l_b)
{
	ft_printf("%s", "pa\n");
	ft_push(l_b, l_a);
}

void			ft_pb(t_list **l_a, t_list **l_b)
{
	ft_printf("%s", "pb\n");
	ft_push(l_a, l_b);
}

int				main(int argc, char **argv)
{
	t_list		**l_a;
	t_list		**l_b;

	if (argc <= 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}

	// ft_printargv(argc, argv);
	l_a = malloc(sizeof(t_list**));
	l_b = malloc(sizeof(t_list**));

	ft_buildlist(l_a, argc, argv);
	// *l_b = NULL;

	ft_sa(l_a);
	ft_printlist(l_a);
	ft_pa(l_a, l_b);
	ft_pa(l_a, l_b);
	ft_printlist(l_a);
	ft_printlist(l_b);
	ft_ss(l_a, l_b);
	ft_printlist(l_a);
	ft_printlist(l_b);

	// ft_printf("<-- DUMP LIST -->\n");

	// ft_printf("l_a :\n");
	// ft_dumplist(l_a);
	// ft_printf("l_b :\n");
	// ft_dumplist(l_b);

	// while (42)
	// 	;
	return (0);
}
