/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:53:26 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char* s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i = i + 1;
	j = 0;
	while (s2[j] && n--)
	{
		s1[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	s1[i] = '\0';
	return (s1);
}
