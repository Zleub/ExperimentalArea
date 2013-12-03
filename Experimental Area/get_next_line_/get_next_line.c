/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 13:02:38 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_chain 	*adopt_some(t_chain *grand_pa, t_chain *pa, t_chain *child)
{
	child = malloc(sizeof(t_chain));
	child->stomach = malloc(sizeof(char) * BUFF_SIZE + 1);
	child->grand_pa = grand_pa;
	child->pa = pa;
	child->child = child;
	return (child);
}

t_chain 	*build_it(int fd, t_chain *grand_pa, t_chain *pa)
{
	t_chain 	*toy_boy;
	int 		check_up;

	toy_boy = adopt_some(grand_pa, pa, NULL);
	pa->child = toy_boy;
	while ((check_up = read(fd, toy_boy->stomach, BUFF_SIZE)) > 0)
	{
		build_it(fd, grand_pa, toy_boy);
	}
	if (check_up == -1)
		return (NULL);
	return (toy_boy);
}

void		fill_it(t_chain *pa, char **line)
{
	int 	i;

	i = 0;
	pa = pa->child;
	while (pa->stomach[i] != '\n' && i <= BUFF_SIZE)
	{
		i = i + 1;
		if (i == BUFF_SIZE + 1)
		{
			*line = ft_strjoin(*line, pa->stomach);
			fill_it(pa, line);
		}
	}
	ft_strncat(*line, pa->stomach, i);
}

int 		get_next_line(int const fd, char **line)
{
	t_chain 		*grand_pa;
	t_chain 		*toy_boy;
	int 			i;
	int 			check_up;

	grand_pa = adopt_some(grand_pa, grand_pa, NULL);
	check_up = read(fd, grand_pa->stomach, BUFF_SIZE);
	if (check_up == -1)
		return (-1);
	toy_boy = build_it(fd, grand_pa, grand_pa);
	if (toy_boy == NULL)
		return (-1);


	while (grand_pa->stomach[i] != '\n')
	{
		i = i + 1;
		if (i == BUFF_SIZE + 1)
		{
			*line = ft_strsub(grand_pa->stomach, 0, BUFF_SIZE);
			fill_it(grand_pa, line);
		}
		else
		{
			*line = ft_strsub(grand_pa->stomach, 0, i);
		}
	}

	ft_putendl("");
	ft_putendl("<-- VAR_DUMP -->");
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putendl("");
	ft_putstr("check_up = ");
	ft_putnbr(check_up);
	ft_putendl("");

	ft_putendl("");
	ft_putendl("<-- DUMP -->");
	ft_putstr("\t dump grand_pa->stomach : ");
	ft_putendl(grand_pa->stomach);
	ft_putstr("\t dump grand_pa->child->stomach : ");
	grand_pa = grand_pa->child;
	ft_putendl(grand_pa->stomach);
	ft_putstr("\t dump toy_boy->stomach : ");
	ft_putendl(toy_boy->stomach);
	ft_putstr("\t dump toy_boy->child->stomach : ");
	toy_boy = toy_boy->child;
	ft_putendl(toy_boy->stomach);
	ft_putstr("\t dump toy_boy->child->child->stomach : ");
	toy_boy = toy_boy->child;
	ft_putendl(toy_boy->stomach);


	 // grand_pa = grand_pa->grand_pa;
	 // *line = grand_pa->stomach;
	return (666);
}
