/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2014/04/14 15:44:11 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			size_cpy;
	size_t			len;
	char			*dst_cpy;
	const char		*src_cpy;

	size_cpy = size;
	dst_cpy = dst;
	src_cpy = src;
	while (*dst_cpy != '\0' && size_cpy-- != 0)
		dst_cpy++;
	len = dst_cpy - dst;
	size_cpy = size - len;
	if (size_cpy == 0)
		return (len + ft_strlen((char *)src_cpy));
	while (*src_cpy != '\0')
	{
		if (size_cpy != 1)
		{
			*dst_cpy++ = *src_cpy;
			size_cpy--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (len + (src_cpy - src));
}
