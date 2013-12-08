/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 00:16:25 by adebray           #+#    #+#             */
/*   Updated: 2013/12/08 06:40:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len)
	{
		res[i] = s[start + i];
		i++;
		len--;
	}
	return (res);
}
