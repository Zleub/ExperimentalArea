/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/23 10:57:30 by adebray          ###   ########.fr       */
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

void			ft_dumplist(t_list *head)
{
	if (!head)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	while (head->next)
	{
		ft_printshackle(head);
		head = head->next;
	}
}

void			ft_printlist(t_list *head)
{
	if (!head)
	{
		ft_putendl_fd("(null)", 2);
		return ;
	}
	while (head->next)
	{
		ft_printf("%d ", head->data);
		head = head->next;
	}
	ft_putendl_fd("", 1);
}


t_list			*ft_buildlist(t_list *head, int argc, char **argv)
{
	t_list		*shackle;
	int			i;

	if (argc <= 1)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	i = 1;
	shackle = ft_initshackle();
	head = shackle;
	while (i < argc)
	{
		shackle->data = ft_atoi(argv[i]);
		shackle->next = ft_initshackle();
		shackle = shackle->next;
		i += 1;
	}
	return (head);
}

t_list			*ft_swap(t_list *head)
{
	t_list		*tmp;

	if (!head)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	return (tmp);
}

// t_list			*ft_push(t_list *dst, t_list *src)
// {
// 	if (!src)
// 	{
// 		ft_putendl_fd("Error", 2);
// 		return (NULL);
// 	}
// 	if ()
// }

int				main(int argc, char **argv)
{
	t_list		**l_a;
	t_list		**l_b;

	// ft_printargv(argc, argv);
	l_a = malloc(sizeof(t_list**));
	l_b = malloc(sizeof(t_list**));

	ft_buildlist(*l_a, argc, argv);
	*l_b = NULL;

	ft_printshackle(*l_a);
	// ft_printf("l_a : %p\n", l_a);
	// ft_printf("*l_a : %p\n", *l_a);

	ft_printf("l_a :\n");
	ft_printlist(*l_a);
	ft_printf("l_b :\n");
	ft_printlist(*l_b);

	*l_a = ft_swap(*l_a);

	ft_printf("l_a (swaped) :\n");
	ft_printlist(*l_a);
	ft_printf("l_b :\n");
	ft_printlist(*l_b);


	// ft_printf("l_a :\n");
	// ft_dumplist(l_a);
	// ft_printf("l_b :\n");
	// ft_dumplist(l_b);

	// l_a = ft_initshackle();
	// ft_printshackle(l_a);
	// while (42)
	// 	;
	return (0);
}
