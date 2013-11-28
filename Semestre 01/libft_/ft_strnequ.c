/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:43 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:38:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_strnequ(char const *s1, char const *s2, size_t n)
{

	if (s1 != NULL && s2 != NULL)
	{
		if(ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
			return (1);
		if (ft_strncmp(s1, s2, n) != 0)
			return (0);
		else
			return (1);
	}
	return (0);
}
