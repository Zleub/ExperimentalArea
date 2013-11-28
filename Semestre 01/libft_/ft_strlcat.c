/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 23:24:32 by adebray           #+#    #+#             */
/*   Updated: 2013/11/27 23:35:25 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int 	_size;
	int 	len;
	char	*_dst;

	_size = size;
	_dst = dst;
	while (*_dst != '\0')
		_dst++;
	len = (_dst - dst) - size;
	if (len == 0 || _size == 0 || src == NULL)
		return (0);
	while (*src && _size-- != 1)
	{
		*_dst = (char)*src;
		src++;
		_dst++;
	}
	if (_size == 1)
	{
		*_dst = '\0';
		return (size + ft_strlen(src));
	}
	*_dst = '\0';
	return ((_dst - dst) + ft_strlen(src));
}
