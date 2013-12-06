/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 21:12:06 by adebray           #+#    #+#             */
/*   Updated: 2013/12/06 05:15:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	get_next_line(int const fd, char **line)
{
	static char	*array;
	char		buffer[BUFF_SIZE];
	int 		i;

	if (!array)
	{
		array = ft_memalloc(1);
		while ((i = read(fd, buffer, BUFF_SIZE - 1)) != 0)
		{
			array = ft_strjoin(array, buffer);
			ft_bzero(buffer, BUFF_SIZE);
			ft_putnbr(i);
			ft_putendl(" ");
		}
	}
	i = 0;
	while (array[i] != '\n')
		i = i + 1;
	*line = ft_strsub(array, 0, i);
	if (i == 0)
		*line = ft_strsub("", 0 , 1);
	array = ft_strsub(array, i + 1, ft_strlen(array));
	if (!array)
		return (0);
	return (1);
}
