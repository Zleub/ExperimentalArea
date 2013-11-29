/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2013/11/29 01:45:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char* str)
{
	int 	i;
	int 	j;
	char	tmp;
	int 	lenght;

	i = 0;
	lenght = ft_strlen(str);
	j = lenght - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

static void	ft_itoa_cut(int *i, int *n, int *sign, char *str)
{
	while (*n > 0)
	{
		str[*i++] = '0' + *n % 10;
		*n = *n / 10;
	}
	if (*sign)
	{
		str[*i++] = '-';
		str[0] += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int 	sign;
	int 	i;

	i = 0;
	sign = 1;
	str = (char*)malloc(sizeof(*str) * 15);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		n = n + 1;
		n = -n;
	}
	else
		sign = 0;
	ft_itoa_cut(&i, &n, &sign, str);
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
