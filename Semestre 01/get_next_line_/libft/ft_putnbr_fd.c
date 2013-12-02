/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:39:46 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp[10];
	int 	i;

	if (n < 10)
	{
		n += '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		i = 0;
		while (n > 10)
		{
			tmp[i] = n % 10 + '0';
			n /= 10;
			i = i + 1;
		}
		n += '0';
		ft_putchar_fd(n, fd);
		while (i >= 0)
		{
			ft_putchar_fd(tmp[i], fd);
			i = i - 1;
		}
	}
}
