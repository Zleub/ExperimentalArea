/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 00:15:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	int 	tmp[10];
	int 	i;

	if (n < 10)
	{
		n += '0';
		ft_putchar(n);
	}
	else
	{
		i = 0;
		while (n > 10)
		{
			tmp[i] = n % 10;
			n /= 10;
			i = i + 1;
		}
		ft_putnbr(n);
		i = i - 1;
		while (i >= 0)
		{
			ft_putnbr(tmp[i]);
			i = i - 1;
		}
	}
}
