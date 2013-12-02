/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 11:18:40 by Arno              #+#    #+#             */
/*   Updated: 2013/12/01 22:20:03 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 	ft_word_nbr(char const *s, char c)
{
	int 	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			i = i + 1;
		}
		else
		{
			while (*s != c)
				s++;
		}
	}
	if (s[ft_strlen(s) - 1] == c && s[ft_strlen(s)] == '\0')
		return (i - 1);
	else
		return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	cmp[3];

	if (s == NULL)
		return (0);
	tab = (char**)malloc(sizeof(char*) * ft_word_nbr(s, c) + 1);
	if (!tab)
		return (0);
	cmp[0] = cmp[3] = 0;
	tab[ft_word_nbr(s, c)] = 0;
	while (cmp[3] < ft_word_nbr(s, c))
	{
		cmp[1] = 0;
		while (s[cmp[0]] == c)
			++cmp[0];
		while (s[cmp[0]] != c)
		{
			++cmp[0];
			++cmp[1];
		}
		tab[cmp[3]] = ft_strsub(s, cmp[0] - cmp[1], cmp[1]);
		++cmp[3];
	}
	return (tab);
}
