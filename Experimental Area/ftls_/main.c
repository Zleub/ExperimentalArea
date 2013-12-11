/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/10 13:16:56 by adebray          ###   ########.fr       */
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

// void	ft_cpy_array(char **dst, char **src)
// {
// 	int 	i;

// 	i = 0;
// 	while (src[i])
// 		i = i + 1;
// 	dst = (char **)malloc(sizeof(char*) * i);
// 	while (i-- != 0)
// 		dst[i] = ft_strdup(src[i]);
// }

// void	ft_cat_array(char **dst, char **src)
// {
// 	int 	i;
// 	int 	j;
// 	int 	k;

// 	i = j = k = 0;
// 	while (dst[i])
// 		i = i + 1;
// 	while (src[j])
// 		j = j + 1;
// 	while (i <= i + j && k++)
// 		dst[i] = ft_strdup(src[k]);
// }

// int 	get_readdir(char **array, char *dir)
// {
// 	DIR				*dirp;
// 	struct dirent	**read;
// 	int 			i;
// 	int 			j;

// 	dirp = opendir(dir);
// 	/* Gestion d'erreur */

// 	i = 0;
// 	while (readdir(dirp))
// 		i = i + 1;
// 	ft_putnbr(i);

// 	closedir(dirp);
// 	/* Gestion d'erreur */


// 	dirp = opendir(dir);
// 	/* Gestion d'erreur */


// 	read = malloc(sizeof(struct dirent*) * i);

// 	ft_putendl("test3");

// 	i = 0;
// 	while ((read[i] = readdir(dirp)))
// 		i = i + 1;

// 	ft_putendl(read[0]->d_name);
// 	ft_putendl("test4");

// 	*array = (char**)malloc(sizeof(char *) * i);

// 	j = 0;
// 	while (j <= i)
// 	{
// 		array[j] = ft_strdup(read[j]->d_name);
// 		j = j + 1;
// 	}

// 	*array[j] = 0;
// 	ft_putendl("test5");

// 	closedir(dirp);
// 	/* Gestion d'erreur */


// 	return (0);
// }

int 	get_read_size(char *dir)
{
	DIR 	*dirp;
	int 	i;

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
	int 			i;
	int 			j;
	int 			len;
	int 			min;
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
	int 			len;
	int 			i;

	len = get_read_size(dir);
	dirp = opendir(dir);
	read = malloc(sizeof(struct dirent*) * i);
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
	free(read);
	return (array);
}

int 	print_basic(char *dir)
{
	int 	i;
	char	**array;

	i = 0;
	array = get_array_d_name(dir);
	while(array[i])
	{
		ft_putendl(array[i]);
		i = i + 1;
	}
	return (0);
}

int 	main(int argc, char **argv)
{
	char			*dir;

	argc = argc;
	argv = argv;

	dir = "./";

	print_basic(dir);

	return (0);
}
