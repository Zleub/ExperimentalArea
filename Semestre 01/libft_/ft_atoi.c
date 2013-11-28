/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:40:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(const char *str, int sign)
{
	int 	nbr;

	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr *= 10;
		nbr += *str++ - '0';
	}
	return (nbr * sign);
}

static int 	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' \
			|| c == ' ')
		return (1);
	else
		return (0);
}

int 		ft_atoi(const char *str)
{
	int 	sign;

	sign = 1;
	while (ft_isspace(*str) || *str == 45 ||  *str == 43)
	{
		if (*str == 45)
		{
			sign = -1;
			str++;
			return (ft_convert(str, sign));
		}
		str++;
	}
	return (ft_convert(str, sign));
}
