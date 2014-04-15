/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 03:46:03 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 22:32:02 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				print_dir(char *dir, t_global *global)
{
	DIR				*dirp;
	t_tmp			*list;
	t_clist			*clist;
	t_clist			*head;

	if (!(dirp = opendir(dir)))
		return (custom_error(dir, 1));
	list = (t_tmp*)malloc(sizeof(t_tmp));
	clist = create_clist();
	head = clist;
	ft_printf("%s:\n", dir);
	while ((list->tmp = readdir(dirp)))
		clist = add_elem_clist(clist, list->tmp->d_name);
	head = remove_last(head);
	head = sort_clist(head);
	if (global->r == 1)
		print_rclist(head, global);
	else
		print_clist(head, global);
	closedir(dirp);
}

char				**sort_time_array(char **array)
{
	int				i;
	int				loop;
	char			*tmp;
	struct stat		buf1;
	struct stat		buf2;

	i = 1;
	while (array[i])
	{
		loop = 0;
		stat(array[i], &buf1);
		stat(array[i + 1], &buf2);
		if (array[i + 1] && buf1.st_mtime - buf2.st_mtime < 0)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			loop = 1;
		}
		if (loop == 1)
			i = 1;
		else
			i += 1;
	}
	return (array);
}

void				print_dir_list(char **array, t_global *global)
{
	int				i;

	i = 0;
	if (!array || !array[0] || !ft_strcmp(array[0], ""))
		return ;
	array = sort_array(array);
	if (global->r == 1)
		array = reverse_array(array);
	if (global->t == 1)
		array = sort_time_array(array);
	while (array[i])
	{
		print_dir(array[i], global);
		if (array[i + 1])
			ft_printf("\n");
		i += 1;
	}
}

void				print_nodir_list(char **array, t_global *global)
{
	int				i;

	i = 0;
	if (!array || !array[0] || !ft_strcmp(array[0], ""))
		return ;
	if (global->t == 1)
		array = sort_time_array(array);
	else
		array = sort_array(array);
	if (global->r == 1)
		array = reverse_array(array);
	while (array[i])
	{
		print_dir(array[i], global);
		i += 1;
	}
	ft_printf("\n");
	ft_printf("\n");
}

void				print_nofile_list(char **array, t_global *global)
{
	int				i;

	i = 0;
	if (!array || !array[0] || !ft_strcmp(array[0], ""))
		return ;
	if (global->t == 1)
		array = sort_time_array(array);
	else
		array = sort_array(array);
	if (global->r == 1)
		array = reverse_array(array);
	while (array[i])
	{
		ft_printf("ls: %s: No such file or directory\n", array[i]);
		i += 1;
	}
	ft_printf("\n");
}
