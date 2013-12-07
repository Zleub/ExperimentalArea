/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/07 23:12:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void 	list_argv(int argc, char **argv)
{
	int 	i;

	i = 1;
	ft_putnbr(argc - 1);
	ft_putendl(" arguments.");
	while (i <= argc - 1)
	{
		ft_putendl(argv[i]);
		i = i + 1;
	}
}

int 	get_name_print(char *dir)
{
	DIR				*dirp;
	struct dirent	*array[100];
	int 			i;
	int 			j;

	dirp = opendir(dir);
	/* Gestion d'erreur */
	i = 0;
	while ((array[i++] = readdir(dirp)))
		/* Gestion d'erreur */;
	closedir(dirp);
	/* Gestion d'erreur */
	j = 0;
	while (j < i - 1)
	{
		ft_putendl(array[j++]->d_name);
	}
	return (0);
}

int 	get_name_array(char **array, char *dir)
{
	DIR				*dirp;
	struct dirent	*tmp[100];
	int 			i;
	int 			j;

	dirp = opendir(dir);
	/* Gestion d'erreur */
	i = 0;
	while ((tmp[i++] = readdir(dirp)))
		/* Gestion d'erreur */;
	closedir(dirp);
	/* Gestion d'erreur */
	j = 0;
	while (j < i - 1)
	{
		array[j] = tmp[j]->d_name;
		j = j + 1;
	}
	return (0);
}

int 	main(int argc, char **argv)
{
	char	*array[100];
	int 	i;

	argc = argc;
	argv = argv;

	i = 0;
	get_name_array(array, "./");
	while (array[i])
		ft_putendl(array[i++]);
	return (0);
}
