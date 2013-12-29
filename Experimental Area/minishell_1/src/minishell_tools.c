/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:35:17 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:38:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_1.h>

int					get_path(char **environ)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (environ[i])
	{
		if (!ft_strncmp("PATH=", environ[i], 5))
			return (i);
		i += 1;
	}
	return (0);
}

char				*get_shell(char **environ)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (environ[i])
	{
		if (!ft_strncmp("SHELL=", environ[i], 6))
		{
			j = ft_strlen(environ[i]);
			while (environ[i][j] != '/')
				j -= 1;
			return (ft_strsub(environ[i], j + 1, ft_strlen(environ[i]) - j));
		}
		i += 1;
	}
	return (NULL);
}

t_binlist			*binlist_init(void)
{
	t_binlist		*binlist;

	binlist = malloc(sizeof(t_binlist));
	binlist->name = NULL;
	binlist->path = NULL;
	binlist->next = NULL;
	return (binlist);
}

void				ft_printshackle(t_binlist *shackle)
{
	if (shackle)
	{
		ft_printf("shackle : %p\n", shackle);
		ft_printf("\tshackle->name : %s\n", shackle->name);
		ft_printf("\tshackle->path : %s\n", shackle->path);
		ft_printf("\tshackle->next : %p\n", shackle->next);
	}
	else
		ft_printf("(no shackle)\n");
}

void				ft_dumpbinlist(t_binlist **head)
{
	t_binlist		*tmp;

	if (!*head)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	tmp = *head;
	while (tmp)
	{
		ft_printshackle(tmp);
		tmp = tmp->next;
	}
}
