/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:10:46 by adebray           #+#    #+#             */
/*   Updated: 2014/03/13 13:16:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		is_room(char *str)
{
	int			j;
	int			i;

	i = j = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			if (i == 0)
				j -= 1;
			while (ft_isspace(str[i]))
			{
				i += 1;
				if (str[i] == '\0')
					j -= 1;
			}
			j += 1;
		}
		i += 1;
	}
	if (j == 2)
		return (1);
	else
		return (0);
}

int		is_pipe(char *str)
{
	int		i;
	int		j;

	i = j= 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			while (ft_isspace(str[i]))
				i += 1;
		}
		if (str[i] == '-' && str[i - 1] && str[i + 1])
			j += 1;
		i += 1;
	}
	return (j);
}
