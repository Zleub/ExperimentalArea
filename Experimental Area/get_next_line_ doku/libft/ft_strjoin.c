/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:42 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 00:13:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s2)
			return (NULL);
		ptr = tmp;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
		return (ptr);
	}
	return (NULL);
}
