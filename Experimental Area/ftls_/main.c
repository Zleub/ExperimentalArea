/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/11 09:39:34 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

// void	list_argv(int argc, char **argv)
// {
// 	int		i;

// 	i = 1;
// 	ft_putnbr(argc - 1);
// 	ft_putendl(" arguments.");
// 	while (i <= argc - 1)
// 	{
// 		ft_putendl(argv[i]);
// 		i = i + 1;
// 	}
// }

int		get_read_size(char *dir)
{
	DIR		*dirp;
	int		i;

	dirp = opendir(dir);
	/* Gestion d'erreur */
	i = 0;
	while (readdir(dirp))
		i = i + 1;
	closedir(dirp);
	/* Gestion d'erreur */
	return (i);
}

void	sort_array_d_name(struct dirent	**read, char *dir)
{
	int				i;
	int				j;
	int				len;
	int				min;
	struct dirent	*tmp;

	len = get_read_size(dir);
	i = 0;
	while (i < len)
	{
		min = i;
		j = i;
		while (j < len)
		{
			if (ft_strcmp(read[min]->d_name, read[j]->d_name) > 0)
			{
				min = j;
			}
			j = j + 1;
		}
		tmp = read[i];
		read[i] = read[min];
		read[min] = tmp;
		i = i + 1;
	}
}

char	**get_array_d_name(char *dir)
{
	DIR				*dirp;
	struct dirent	**read;
	char			**array;
	int				len;
	int				i;

	len = get_read_size(dir);
	dirp = opendir(dir);
	read = malloc(sizeof(struct dirent**));
	i = 0;
	while (i < len)
		read[i++] = malloc(sizeof(struct dirent*));
	array = malloc(sizeof(char *) * i);
	i = 0;
	while ((read[i] = readdir(dirp)))
		i = i + 1;
	sort_array_d_name(read, dir);
	i = 0;
	while (read[i])
	{
		array[i] = ft_strdup(read[i]->d_name);
		i = i + 1;
	}
	closedir(dirp);
	return (array);
}

int		print_basic(char *dir, t_global *variables)
{
	int				len;
	int				i;
	char			**array;

	i = 0;
	len = get_read_size(dir);
	array = get_array_d_name(dir);
	while(i < len)
	{
		if (variables-> a == 1)
			ft_putendl(array[i]);
		else
		{
			if (array[i][0] != '.')
				ft_putendl(array[i]);
		}
		i = i + 1;
	}
	return (0);
}

t_global	*bools_init(t_global *variables)
{
	variables = malloc(sizeof(t_global *));
	variables->a = 0;
	variables->l = 0;
	variables->nb_folds = 0;
	return (variables);
}

t_global	*tea_time(t_global *variables, int argc, char** argv, int i)
{
	int		j;

	variables->nb_folds = argc - i;
	variables->folders = malloc(sizeof(char*) * variables->nb_folds);
	j = 0;
	while (i < argc)
	{
		variables->folders[j] = ft_strdup(argv[i]);
		i = i + 1;
		j = j + 1;
	}
	return (variables);
}

t_global	*parsing(int argc, char **argv, t_global *variables)
{
	int		i;
	int		j;

	variables = bools_init(variables);
	i = 1;
	while (i < argc && (!ft_isalnum(argv[i][0])))
	{
		if (i < argc && argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == 'a')
					variables->a = 1;
				else if (argv[i][j] == 'l')
					variables->l = 1;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	variables = tea_time(variables, argc, argv, i);
	return (variables);
}

int		main(int argc, char **argv)
{
	int				i;
	char			*dir;
	t_global		*variables;

	argc = argc;

	dir = "./";
	variables = parsing(argc, argv, variables);

	// ft_putstr("parsing time, a : ");
	// ft_putnbr(variables->a);
	// ft_putstr(" l : ");
	// ft_putnbr(variables->l);
	// ft_putstr(" . ");
	// ft_putendl(variables->folders[0]);
	// ft_putendl(variables->folders[1]);

	if(!variables->folders[0] && !variables->folders[1])
		print_basic(dir, variables);

	if(variables->folders[0] && !variables->folders[1])
		print_basic(variables->folders[0], variables);

	if (variables->folders[0] && variables->folders[1])
	{
		i = 0;
		while (variables->folders[i] && i < variables->nb_folds)
		{
			ft_putstr(variables->folders[i]);
			ft_putendl(":");
			print_basic(variables->folders[i], variables);
			if (i < variables->nb_folds - 1)
				ft_putendl("");
			i = i + 1;
		}
	}
	return (0);
}
