/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 00:10:23 by adebray           #+#    #+#             */
/*   Updated: 2013/12/07 04:03:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t 	ft_word_nbr(char const *s, char c)
{
	size_t	 	i;

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

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	cmp[3];

	if (s == NULL)
		return (0);
	tab = (char**)malloc(sizeof(char*) * ft_word_nbr(s, c) + 1);
	if (!tab)
		return (0);
	cmp[0] = cmp[2] = 0;
	tab[ft_word_nbr(s, c)] = 0;
	while (cmp[2] < ft_word_nbr(s, c))
	{
		cmp[1] = 0;
		while (s[cmp[0]] == c)
			++cmp[0];
		while (s[cmp[0]] != c)
		{
			++cmp[0];
			++cmp[1];
		}
		tab[cmp[2]] = ft_strsub(s, cmp[0] - cmp[1], cmp[1]);
		++cmp[2];
	}
	return (tab);
}
