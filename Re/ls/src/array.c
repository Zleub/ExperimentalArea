/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 18:24:42 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 22:09:01 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			**sort_array(char **array)
{
	int			i;
	int			loop;
	char		*tmp;

	i = 0;
	while (array[i])
	{
		loop = 0;
		if (array[i + 1] && ft_strcmp(array[i], array[i + 1]) > 0)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			loop = 1;
		}
		if (loop == 1)
			i = 0;
		else
			i += 1;
	}
	return (array);
}

void			add_to_array(char **array, char *str)
{
	int			i;

	i = 0;
	while (array[i])
	{
		i += 1;
	}
	array[i] = ft_strdup(str);
}

char			**reverse_array(char **array)
{
	char		**rarray;
	int			i;
	int			j;

	i = 0;
	j = get_array_size(array);
	rarray = ft_malloc(j);
	while (array[i])
	{
		rarray[j - 1] = ft_strdup(array[i]);
		j -= 1;
		i += 1;
	}
	return (rarray);
}
