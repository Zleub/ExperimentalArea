/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:43 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:38:08 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;
	char	*p;

	if (c == '\0')
	{
		return (char*)(s + ft_strlen(s));
	}
	length = ft_strlen(s);
	p = (char*)(s + ft_strlen(s));
	while (length--)
	{
		if (*p != (unsigned char)c)
			p--;
		else
			return (char*)(p);
	}
	return (NULL);
}
