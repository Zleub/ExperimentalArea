/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:06:37 by adebray           #+#    #+#             */
/*   Updated: 2013/12/21 16:36:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int							ft_puthexa(unsigned int decimal)
{
	static int				cmp;

	cmp = 0;
	if (decimal < 16)
	{
		if (decimal == 10)
			cmp += ft_printf("%c", 'a');
		else if (decimal == 11)
			cmp += ft_printf("%c", 'b');
		else if (decimal == 12)
			cmp += ft_printf("%c", 'c');
		else if (decimal == 13)
			cmp += ft_printf("%c", 'd');
		else if (decimal == 14)
			cmp += ft_printf("%c", 'e');
		else if (decimal == 15)
			cmp += ft_printf("%c", 'f');
		else
			cmp += ft_printf("%d", decimal);
	}
	else
	{
		ft_puthexa(decimal / 16);
		ft_printf("%x", decimal % 16);
	}
	return (cmp);
}
