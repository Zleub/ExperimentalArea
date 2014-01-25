/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:36:05 by adebray           #+#    #+#             */
/*   Updated: 2014/01/25 11:52:28 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_gnl				*create(void)
{
	t_gnl			*elem;

	elem = malloc(sizeof(t_gnl));
	elem->str = NULL;
	elem->next = NULL;
	return (elem);
}

int					*get_dual(t_gnl *head)
{
	int				*size;
	char			*str;

	size = NULL;
	str = head->str;
	size = malloc(sizeof(int) * 3);

	while (!ft_isdigit(*str))
	{
		str++;
	}
	size[0] = ft_atoi(str);
	while(ft_isdigit(*str))
		str++;
	size[1] = ft_atoi(str);
	size[2] = 0;
	return (size);
}

char				**get_piece(int *piece_size)
{
	char			**piece;
	int				i;
	int				j;

	i = piece_size[0];
	j = 0;
	piece = malloc(sizeof(char*) * i + 1);
	while (i--)
	{
		get_next_line(0, &piece[j]);
		j += 1;
	}
	piece[j] = NULL;
	return (piece);
}

char				**get_plat(int *plateau_size)
{
	char			**plateau;
	char			*str;
	int				i;
	int				j;
	int				k;

	i = plateau_size[0];
	j = 0;
	plateau = malloc(sizeof(char*) * i + 1);
	while (i--)
	{
		get_next_line(0, &str);
		k = 0;
		while (ft_isdigit(str[k]))
			k += 1;
		plateau[j] = ft_strsub(str, k + 1, ft_strlen(str));
		j += 1;
	}
	plateau[j] = NULL;
	return (plateau);
}

