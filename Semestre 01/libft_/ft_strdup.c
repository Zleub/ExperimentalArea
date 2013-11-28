/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:38:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int 	i;

	i = 0;
	dup = malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	else
		while(s1[i] != '\0')
		{
			dup[i] = s1[i];
			i = i + 1;
		}
		dup[i] = '\0';
	return (dup);
}
