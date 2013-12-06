/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 21:12:06 by adebray           #+#    #+#             */
/*   Updated: 2013/12/06 09:36:21 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* int 	get_next_line(int const fd, char **line)
{
	static char	*array;
	char		buffer[BUFF_SIZE];
	int 		i;

	if (!array)
	{
		array = ft_memalloc(1);
		while ((i = read(fd, buffer, BUFF_SIZE - 1 )) != 0)
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
} */

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*tmp;
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
		if (!s2)
			return (NULL);
		ptr = tmp;
		while (*s1)
			*tmp++ = *s1++;
		while (n--)
			*tmp++ = *s2++;
		*tmp = '\0';
		return (ptr);
	}
	return (NULL);
}

int 	get_next_line(int const fd, char **line)
{
	static char *array;
	char		buffer[BUFF_SIZE + 1] = {'\0'};
	int 		i;

	i = 0;
	if (!array)
		array = ft_memalloc(1);
	else if (ft_strchr(array, '\n') != NULL)
	{
		while (array[i] != '\n')
			i = i + 1;
		if (i == 0)
			*line = ft_strsub("", 0, 1);
		else
			*line = ft_strsub(array, 0, i);
		array = ft_strsub(array, i + 1, ft_strlen(array) - i);
		return (1);
	}
	i = 0;
	if (read(fd, buffer, BUFF_SIZE) == 0)
		return (0);
	while (buffer[i] != '\n' && i <= BUFF_SIZE)
		i = i + 1;
	if (i == BUFF_SIZE + 1)
	{
		array = ft_strjoin(array, buffer);
		get_next_line(fd, line);
	}
	else
	{
		*line = ft_strnjoin(array, buffer, i);
		array = ft_strsub(buffer, i + 1, ft_strlen(buffer) - i);
	}
	return (1);
}
