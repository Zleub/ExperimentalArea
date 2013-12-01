/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:17:15 by Arno              #+#    #+#             */
/*   Updated: 2013/12/01 22:19:43 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int 	length;
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
