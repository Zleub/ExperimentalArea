/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:43 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 12:37:55 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int 	i;
	int 	j;

	i = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == 10 || s[i] == 9)
		i = i - 1;
	j = 0;
	while (s[j] == 32 || s[j] == 10 || s[j] == 9)
		j = j + 1;
	if (j == ft_strlen(s))
	{
		tmp[0] = '\0';
		return (tmp);
	}
	tmp = ft_strsub(s, j, i - j + 1);
	return (tmp);
}
