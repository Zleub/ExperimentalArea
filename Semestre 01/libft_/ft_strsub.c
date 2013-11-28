/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:43 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:37:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int 	i;
	char	*s2;

	if (s != NULL)
	{
		s2 = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		i = 0;
		while ((len + 1) > 1)
		{
			s2[i] = s[start];
			start = start + 1;
			i = i + 1;
			len = len - 1;
		}
		return (s2);
	}
	return (NULL);
}
