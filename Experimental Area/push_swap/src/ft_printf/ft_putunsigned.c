/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 11:46:03 by adebray           #+#    #+#             */
/*   Updated: 2013/12/20 12:04:45 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putunsigned(unsigned int n)
{
	static unsigned int	r;

	r = 0;
	if (n > 9)
	{
			ft_putnbr(n / 10);
			r += 1;
	}
	ft_putchar(n % 10 + '0');
	return (r + 1);
}
