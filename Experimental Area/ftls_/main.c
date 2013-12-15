/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/15 06:14:33 by adebray          ###   ########.fr       */
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
	if (!dirp)
		return (-1);
	i = 0;
	while (readdir(dirp))
		i = i + 1;
	if (i == 0)
		return (-1);
	if (closedir(dirp) == -1)
		return (-1);
	return (i);
}

// void	sort_array_dirent(struct dirent **read, char *dir)
// {
// 	int				i;
// 	int				j;
// 	int				len;
// 	int				min;
// 	struct dirent	*tmp;

// 	len = get_read_size(dir);
// 	i = 0;
// 	while (i < len)
// 	{
// 		min = i;
// 		j = i;
// 		while (j < len)
// 		{
// 			if (ft_strcmp(read[min]->d_name, read[j]->d_name) > 0)
// 			{
// 				min = j;
// 			}
// 			j = j + 1;
// 		}
// 		tmp = read[i];
// 		read[i] = read[min];
// 		read[min] = tmp;
// 		i = i + 1;
// 	}
// }

void	sort_array_argv(char **array, int len ,int i)
{
	int				j;
	int				min;
	char			*tmp;

	while (i < len)
	{
		min = i;
		j = i;
		while (j < len)
		{
			if (ft_strcmp(array[min], array[j]) > 0)
			{
				min = j;
			}
			j = j + 1;
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		i = i + 1;
	}
}

struct dirent	**get_array_dirent(char *dir, int len)
{
	DIR				*dirp;
	struct dirent	**read;
	int				i;

	dirp = opendir(dir);
	if (!dirp)
		return (NULL);
	read = malloc(sizeof(struct dirent**));
	i = 0;
	while (i < len)
		read[i++] = malloc(sizeof(struct dirent*));
	i = 0;
	while ((read[i] = readdir(dirp)))
		i = i + 1;
	if (read[i - 1] == NULL)
		return (NULL);
	if (closedir(dirp) == -1)
		return (NULL);
	return (read);
}

// char	**get_array_d_name(char *dir)
// {
// 	DIR				*dirp;
// 	struct dirent	**read;
// 	char			**array;
// 	int				len;
// 	int				i;

// 	len = get_read_size(dir);
// 	dirp = opendir(dir);
// 	read = malloc(sizeof(struct dirent**));
// 	i = 0;
// 	while (i < len)
// 		read[i++] = malloc(sizeof(struct dirent*));
// 	array = malloc(sizeof(char *) * i);
// 	i = 0;
// 	while ((read[i] = readdir(dirp)))
// 		i = i + 1;
// 	sort_array_dirent(read, dir);
// 	i = 0;
// 	while (read[i])
// 	{
// 		array[i] = ft_strdup(read[i]->d_name);

// 		ft_putstr(read[i]->d_name);
// 		ft_putstr(" : ");
// 		ft_putnbr(read[i]->d_type);
// 		ft_putendl(".");
// 		i = i + 1;
// 	}
// 	closedir(dirp);
// 	return (array);
// }

t_global	*glob_init(t_global *vars)
{
	vars = malloc(sizeof(t_global *));
	vars->a = 0;
	vars->l = 0;
	vars->read = get_array_dirent("./", get_read_size("./"));
	vars->folders = NULL;
	vars->files = NULL;
	return (vars);
}

// t_global	*tea_time(t_global *vars, int argc, char** argv, int i)
// {
// 	int		j;

// 	vars->nb_folds = argc - i;
// 	vars->folders = malloc(sizeof(char*) * vars->nb_folds);
// 	vars->read = get_array_dirent()
// 	j = 0;
// 	while (i < argc)
// 	{
// 		vars->folders[j] = ft_strdup(argv[i]);
// 		i = i + 1;
// 		j = j + 1;
// 	}
// 	while
// 	return (vars);
// }

int		print_basic_dir(char *dir, t_global *vars)
{
	int				len;
	int				i;
	struct dirent	**read;

	i = 0;
	len = get_read_size(dir);
	if (len == -1)
		return (-1);
	read = get_array_dirent(dir, len);
	if (!read)
		return (0);
	while(i < len)
	{
		if (vars->a == 1)
			ft_putendl(read[i]->d_name);
		else
		{
			if (read[i]->d_name[0] != '.')
				ft_putendl(read[i]->d_name);
		}
		i = i + 1;
	}
	return (0);
}

char	**load_basic_dir(char *dir, t_global *vars)
{
	int				len;
	int				i;
	struct dirent	**read;
	char			**array;

	i = 0;
	len = get_read_size(dir);
	if (len == -1)
		return (NULL);
	read = get_array_dirent(dir, len);
	array = malloc(sizeof(char**));
	if (!read)
		return (NULL);

	while (read[i])
	{
		ft_putendl(read[i]->d_name);
		i = i + 1;
	}

	i = 0;
	while (i < len)
	{
		if (vars->a == 1)
			array[i] = ft_strdup(read[i]->d_name);
		else
		{
			if (read[i]->d_name[0] != '.')
				array[i] = ft_strdup(read[i]->d_name);
		}
		i = i + 1;
	}
	array[i] = NULL;
	i = 0;
	while (array[i])
		ft_putendl(ft_strjoin(array[i++], " < prout"));
	return (array);
}


void	treat_plague(t_global *vars, int argc, char** argv, int i)
{
	int		j;
	int		k;
	char	***save;

	k = 0;
	save = malloc(sizeof(char***));
	while (i < argc)
	{
		ft_putnbr(i);
		ft_putendl(" < i");
		ft_putendl(argv[i]);
		save[k] = load_basic_dir(argv[i], vars);
		if (!save[k])
			ft_putendl(strerror(errno));
		else
		{
			j = 0;
			while (save[k][j])
			{
				ft_putendl(save[k][j]);
				j = j + 1;
			}
		}
		i = i + 1;
		k = k + 1;
//		treat_plague(vars, argc, argv, i);
	}
	while (k)
	{
		k = k - 1;
		if (save[k])
		{
		j = 0;
		while (save[k][j])
			ft_putendl(save[k][j++]);
		}
	}
	return ;
}

t_global	*tea_time(t_global *vars, int argc, char** argv, int i)
{
	int		j;

	while (i < argc)
	{
		j = 0;
		while (j <= (int)ft_strlen(argv[i]) && argv[i][j] != '/')
			j = j + 1;
		ft_putstr("j : ");
		ft_putnbr(j);
		ft_putstr(" strlen : ");
		ft_putnbr((int)ft_strlen(argv[i]));
		ft_putstr(" argv : ");
		ft_putendl(argv[i]);
		if (j < (int)ft_strlen(argv[i]))
			ft_putendl("<");
		else if (j > (int)ft_strlen(argv[i]))
			ft_putendl(">");
		else
			ft_putendl("else");
		i = i + 1;
	}
	return (vars);
}

t_global	*parsing(int argc, char **argv, t_global *vars)
{
	int		i;
	int		j;

	vars = glob_init(vars);
	i = 1;
	while (i < argc && (!ft_isalnum(argv[i][0])))
	{
		if (i < argc && argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == 'a')
					vars->a = 1;
				else if (argv[i][j] == 'l')
					vars->l = 1;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	sort_array_argv(argv, argc, i);
	treat_plague(vars, argc, argv, i);

	return (vars);
}

void	recurs(int i)
{
	int		j;

	j = 0;
	if (i <= 10)
	{
		ft_putnbr(i);
		ft_putendl_fd(" < i | out > 2", 2);
		i = i + 1;
		j = j + 1;
		recurs(i);
	}
	ft_putnbr(j);
	ft_putendl(" < j");
	if (j == 1)
	{
		ft_putnbr(i);
		ft_putendl_fd(" < i | out > 1", 1);
	}
	return ;
}

int		main(int argc, char **argv)
{
	// int				i;
	t_global		*vars;

	vars = NULL;
	vars = parsing(argc, argv, vars);

	// ft_putstr("parsing time, a : ");
	// ft_putnbr(vars->a);
	// ft_putstr(" l : ");
	// ft_putnbr(vars->l);
	// ft_putstr(" . ");
	// ft_putendl(vars->folders[0]);
	// ft_putendl(vars->folders[1]);

	ft_putendl("<----->");

	// ft_putendl("dump vars->read sorted");

	// i = 0;
	// while (vars->read[i])
	// {
	// 	ft_putstr("i : ");
	// 	ft_putnbr(i);
	// 	ft_putendl(";");
	// 	ft_putstr("vars->read[i]->d_type : ");
	// 	ft_putnbr(vars->read[i]->d_type);
	// 	ft_putendl(";");
	// 	ft_putstr("vars->read[i]->d_name : ");
	// 	ft_putstr(vars->read[i]->d_name);
	// 	ft_putendl(";");
	// 	ft_putstr("vars->read[i]->d_ino : ");
	// 	ft_putnbr(vars->read[i]->d_ino);
	// 	ft_putendl(";");
	// 	// ft_putstr("vars->read[i]->d_off : ");
	// 	// ft_putnbr(vars->read[i]->d_off);
	// 	// ft_putendl(";");
	// 	ft_putstr("vars->read[i]->d_reclen : ");
	// 	ft_putnbr(vars->read[i]->d_reclen);
	// 	ft_putendl(";");
	// 	i = i + 1;
	// }
	// ft_putendl("<----->");

	// ft_putstr("vars->l");
	// ft_putnbr(vars->l);
	// ft_putendl(";");
	// ft_putstr("vars->a");
	// ft_putnbr(vars->a);
	// ft_putendl(";");

	// ft_putendl("<----->");

	// ft_putendl("perror test");

	// perror("test");

	// ft_putendl("<----->");

	// i = 0;
	// while (vars->folders[i])
	// {
	// 	ft_putstr("i : ");
	// 	ft_putnbr(i);
	// 	ft_putendl(";");
	// 	ft_putstr("vars->folders[i] : ");
	// 	ft_putstr(vars->folders[i]);
	// 	ft_putendl(";");
	// 	i = i + 1;
	// }

	// ft_putendl("print recursively");

	// recurs(0);

	// ft_putendl("<----->");

	// ft_putendl("perror test 2");
	// print_basic_dir("./main", vars);
	// perror("test");

	// ft_putendl("<----->");

	// ft_putendl("print_basic_dir(\"./\")");
	// print_basic_dir("./", vars);

	// ft_putendl("<----->");

	// if(!vars->folders[0] && !vars->folders[1])
	// 	print_basic_dir("./", vars);

	// if(vars->folders[0] && !vars->folders[1])
	// 	print_basic_dir(vars->folders[0], vars);

	// if (vars->folders[0] && vars->folders[1])
	// {
	// 	i = 0;
	// 	while (vars->folders[i] && i < vars->nb_folds)
	// 	{
	// 		ft_putstr(vars->folders[i]);
	// 		ft_putendl(":");
	// 		print_basic_dir(vars->folders[i], vars);
	// 		if (i < vars->nb_folds - 1)
	// 			ft_putendl("");
	// 		i = i + 1;
	// 	}
	// }
	return (0);
}
