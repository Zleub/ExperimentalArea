/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:39:29 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_1.h>

char				**cleararray(char **array)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (array[i])
	{
		i += 1;
		if (array[i] && !ft_strcmp(array[0], array[i]))
		{
			j = i;
		}
	}
	if (j != i)
	{
		while (j < i)
		{
			free (array[j]);
			array[j] = NULL;
			j += 1;
		}
	}
	return (array);
}

void				ft_bin(DIR *dirp, t_binlist *binlist, char **array)
{
	struct dirent	*tmp;
	int				i;

	i = 0;
	while (array[i])
	{
		dirp = opendir(array[i]);
		while ((tmp = readdir(dirp)))
		{
			if (ft_strcmp(".", tmp->d_name) && ft_strcmp("..", tmp->d_name))
			{
				binlist->name = ft_strdup(tmp->d_name);
				binlist->path = array[i];
				binlist->next = binlist_init();
				binlist = binlist->next;
			}
		}
		closedir(dirp);
		i += 1;
	}
}

void				build_bin(t_vars *vars, char **environ)
{
	char			**array;
	DIR				*dirp;
	t_binlist		*binlist;

	array = ft_strcsplit(environ[get_path(environ)], ':', 5);
	array = cleararray(array);
	binlist = binlist_init();
	*vars->binlist = binlist;
	ft_bin(dirp, binlist, array);
}

void				ft_search(t_vars *vars, t_binlist *binlist, char *str)
{
	int				i;

	i = 0;
	while (binlist->next)
	{
		if (!ft_strcmp(binlist->name, str))
		{
			ft_printf("FOUND : %s @ %s\n", binlist->name, binlist->path);
			i = 1;
		}
		binlist = binlist->next;
	}
	if (ft_strcmp("exit", str) && ft_strcmp("logout", str))
	{
		if (i == 0 && str[0] != '\0')
			ft_printf("%s: command not found: %s\n", vars->shell, str);
		free(str);
		str = NULL;
	}
}

int					main(void)
{
	extern char		**environ;
	t_vars			*vars;
	char			*str;
	t_binlist		*binlist;

	vars = malloc(sizeof(t_vars*));
	vars->binlist = malloc(sizeof(t_binlist*));
	vars->shell = get_shell(environ);
	build_bin(vars, environ);
	ft_dumpbinlist(vars->binlist);
	binlist = *vars->binlist;
	while (!str || (ft_strcmp("exit", str) && ft_strcmp("logout", str)))
	{
		binlist = *vars->binlist;
		ft_printf("-> ");
		if (get_next_line(0, &str) > 0)
			ft_search(vars, binlist, str);
	}
	return (0);
}
