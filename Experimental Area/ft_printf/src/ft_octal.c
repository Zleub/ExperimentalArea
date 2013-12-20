/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 12:38:16 by adebray           #+#    #+#             */
/*   Updated: 2013/12/20 18:18:10 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int							ft_putoctal(unsigned int decimal)
{
	unsigned long int		diviser;
	int						octal;
	static int				cmp;

	diviser = 8;
	cmp = 0;
	octal = 0;
	while (diviser <= decimal)
		diviser *= 8;
	diviser /= 8;
	if (decimal >= 8)
	{
		octal *= 10;
		octal += decimal / diviser;
		ft_putnbr(octal);
		decimal -= (diviser * octal);
		diviser /= 8;
		ft_putoctal(decimal);
		cmp += 1;
		return (cmp);
	}
	else
	{
		octal *= 10;
		octal += decimal / diviser;
		decimal = decimal - (diviser * (decimal / diviser));
		ft_putnbr(octal);
		cmp += 1;
		return (cmp);
	}
}
