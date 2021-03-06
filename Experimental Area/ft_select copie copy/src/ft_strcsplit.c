/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 00:10:23 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:19:36 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			word_count(const char *s, char c)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++j;
			while (s[i] != c)
			{
				if (!s[i])
					return (j);
				++i;
			}
		}
		++i;
	}
	return (j);
}

static int			word_len(const char *s, int i, int j, char c)
{
	while (s[i] != c && s[i])
	{
		++i;
		++j;
	}
	return (j);
}

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;

	i = start;
	if (s == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < (start + len))
	{
		new[i - start] = s[i];
		i++;
	}
	new[i - start] = '\0';
	return (new);
}

char				**ft_strcsplit(char const *s, char c, int start)
{
	char			**ret;
	int				i;
	int				k;
	int				word;

	if (!s)
		return (0);
	word = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * word + 1);
	if (!ret)
		return (0);
	i = start;
	k = 0;
	ret[word] = 0;
	while (k < word)
	{
		while (s[i] == c)
			++i;
		ret[k] = ft_strsub(s, i, word_len(s, i, 0, c));
		while (s[i++] != c)
			;
		++k;
	}
	return (ret);
}
