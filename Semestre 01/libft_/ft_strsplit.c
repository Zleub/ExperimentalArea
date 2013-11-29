/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2013/11/29 01:35:03 by adebray          ###   ########.fr       */
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

static int  	ft_word_size(char const *s, char c)
{
	int 	j;
	int 	k;

	j = k = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			j = 0;
			while (*s != c)
			{
				j = j + 1;
				s++;
			}
			if (j > k)
				k = j;
		}
	}
	return (j);
}

static char 	**ft_fill_it(char **_array, char const *s, char c)
{
	int 	l;
	int 	m;

	l = m = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			m = 0;
			while (*s != c)
			{
				_array[l][m] = *s++;
				m = m + 1;
			}
			l = l + 1;
		}
	}
	return (_array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int 	word_nbr;
	int 	word_size;
	int 	i;

	word_nbr = ft_word_nbr(s, c);
	word_size = ft_word_size(s, c);
	tmp = (char**) malloc(sizeof(char*) * word_nbr);
	i = 0;
	while (i < word_nbr)
	{
		tmp[i] = (char*)malloc(sizeof(char) * word_size);
		i = i + 1;
	}
	ft_fill_it(tmp, s, c);
	return (tmp);
}
