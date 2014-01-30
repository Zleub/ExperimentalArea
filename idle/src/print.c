/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 05:53:24 by adebray           #+#    #+#             */
/*   Updated: 2014/01/28 15:08:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>

void				give_info(t_heros *heros, t_heros *monster, int i, LIFE)
{
	ft_putstr("Round : ");
	ft_putnbr(i);
	ft_putendl(NULL);
	print_heros(heros);
	ft_putstr("\tAnd got : ");
	ft_putnbr(h_life);
	ft_putendl(" live.");
	print_heros(monster);
	ft_putstr("\tAnd got : ");
	ft_putnbr(m_life);
	ft_putendl(" live.");
}

void				print_heros(t_heros *heros)
{
	ft_putendl(heros->name);
	ft_putstr("\tHas ");
	ft_putnbr(heros->strengh);
	ft_putendl(" strengh");
	ft_putstr("\tHas ");
	ft_putnbr(heros->defense);
	ft_putendl(" defense");
}
