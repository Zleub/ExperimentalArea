/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 03:42:33 by adebray           #+#    #+#             */
/*   Updated: 2013/11/28 14:53:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        ft_atoi(const char *str)
{
    int        i;
    int        value;
    int        negative;

    value = 0;
    negative = 1;
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            negative *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = 10 * value + (str[i] - '0');
        i++;
    }
    return (value * negative);
}
