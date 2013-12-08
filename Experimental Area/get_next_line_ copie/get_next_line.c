/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 21:12:06 by adebray           #+#    #+#             */
/*   Updated: 2013/12/08 00:59:38 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char		*tmp;
	char		*ptr;

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

int 	get_next_read(int const fd, char **line, char **array)
{
	int 		i;
	char 		buffer[BUFF_SIZE + 1] = {'\0'};

	i = 0;
	if (read(fd, buffer, BUFF_SIZE) == 0)
	{
		*line = ft_strsub(*array, 0, ft_strlen(*array));
		return (0);
	}
	while (buffer[i] != '\n' && i <= BUFF_SIZE)
		i = i + 1;
	if (i == BUFF_SIZE + 1)
	{
		*array = ft_strjoin(*array, buffer);
		get_next_line(fd, line);
	}
	else
	{
		*line = ft_strnjoin(*array, buffer, i);
		*array = ft_strsub(buffer, i + 1, ft_strlen(buffer) - i);
	}
	return (1);
}

int 	get_next_line(int const fd, char **line)
{
	static char *array;
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
	if (get_next_read(fd, line, &array) == 0)
		return (0);
	return (1);
}
