/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/12/10 12:19:56 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// void	ft_putnbr(int n)
// {
// 	ft_putstr(ft_itoa(n));
// }

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n < 0)
	{
		if (n < -9)
			ft_putnbr(n / -10);
		ft_putchar(n % 10 * -1 + '0');
	}
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
