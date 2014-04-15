/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:55:12 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 22:18:37 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	**ft_malloc(int argc)
{
	int		i;
	char	**array;

	i = 0;
	array = (char**)malloc(sizeof(char*) * argc);
	while (array[i])
	{
		array[i] = NULL;
		i += 1;
	}
	return (array);
}

void	check_dir(int argc, char **argv, t_global *global)
{
	DIR				*dirp;
	char			**nodir_list;
	char			**dir_list;
	char			**nofile_list;
	int				i;

	nofile_list = ft_malloc(argc);
	nodir_list = ft_malloc(argc);
	dir_list = ft_malloc(argc);
	i = 0;
	while (i < global->nb_dir)
	{
		if (!(dirp = opendir(argv[i])) && errno == 2)
			add_to_array(nofile_list, argv[i]);
		else if (!dirp && errno != 13)
			add_to_array(nodir_list, argv[i]);
		else
			add_to_array(dir_list, argv[i]);
		i += 1;
	}
	print_nofile_list(nofile_list, global);
	print_nodir_list(nodir_list, global);
	print_dir_list(dir_list, global);
}

char	**get_option(t_global *global, int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == 'r')
				global->r = 1;
			else if (argv[i][j] == 't')
				global->t = 1;
			else if (argv[i][j] == 'a')
				global->a = 1;
			else
				illegal_argument(argv[i][j]);
			j += 1;
		}
		i += 1;
	}
	return (&argv[i]);
}

int		get_array_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i += 1;
	return (i);
}

int		main(int argc, char **argv)
{
	t_global	*global;
	char		**array;

	global = create_global();
	array = get_option(global, argc, argv);
	global->nb_dir = get_array_size(array);
	if (global->nb_dir > 1)
	{
		check_dir(argc, array, global);
	}
	else if (global->nb_dir == 1)
		print_basic_dir(array[0], global);
	else
		print_basic_dir("./", global);
}
