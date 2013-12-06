/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:01:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/04 20:02:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int 		get_next_line(int const fd, char **line)
{
	static char	*array;
	char		*buffer;
	int 		check_up;
	int 		i;

	ft_putendl("--> start it");
	buffer = malloc(sizeof(char) * BUFF_SIZE);
	check_up = read(fd, buffer, BUFF_SIZE);
	if (check_up == 0 && !array)
	{
//		*line = ft_strsub(array, 0, ft_strlen(array));
		return (0);
	}
	i = 0;
	while (buffer[i] != '\n' && i <= BUFF_SIZE)
		i = i + 1;
	ft_putstr("i : ");
	ft_putnbr(i);
	ft_putstr(" buffer : ");
	ft_putendl(buffer);
	ft_putstr("array : ");
	if (array)
		ft_putendl(array);
	else ft_putendl("");
	if(i == BUFF_SIZE + 1)
	{
		ft_putendl("i == BUFF_SIZE + 1");
		array = ft_strsub(buffer, 0, BUFF_SIZE);
//		get_next_line(fd, line);
	}
	else
	{
		ft_putendl("if not");
		array = ft_strnjoin(array, buffer, i);
//		get_next_line(fd, line);
	}
//	array = ft_strsub(buffer, i + 1, i - BUFF_SIZE);
	*line = ft_strsub(array, 0, ft_strlen(array));
	free (array);
	if (i != BUFF_SIZE + 1)
		array = ft_strsub(buffer, i + 1, ft_strlen(buffer) - (i + 1));

	ft_putstr("array before recurs : ");
	if (array)
		ft_putendl(array);
	ft_putstr("line before recurs : ");
	if (*line)
		ft_putendl(*line);
	get_next_line(fd, line);
	ft_putendl("check_up");
//	array = ft_strnjoin(array, buffer, i);
//	array = ft_strsub(buffer, i + 1, i - BUFF_SIZE);
//	*line = ft_strsub(array, 0, ft_strlen(array));

	free(buffer);
	return (1);
}
