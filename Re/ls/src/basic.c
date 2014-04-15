/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 03:45:16 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 22:06:47 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_clist				*sort_clist(t_clist *head)
{
	t_clist			*clist;
	int				loop;
	char			*tmp;

	clist = head;
	while (clist->next)
	{
		loop = 0;
		if (clist->next && ft_strcmp(clist->tmp, clist->next->tmp) > 0)
		{
			tmp = clist->tmp;
			clist->tmp = clist->next->tmp;
			clist->next->tmp = tmp;
			loop = 1;
		}
		if (loop == 1)
			clist = head;
		else
			clist = clist->next;
	}
	return (head);
}

t_clist				*sort_time_clist(t_clist *head)
{
	t_clist			*clist;
	int				loop;
	char			*tmp;
	struct stat		buf1;
	struct stat		buf2;

	clist = head;
	while (clist->next)
	{
		loop = 0;
		stat(clist->tmp, &buf1);
		stat(clist->next->tmp, &buf2);
		if (clist->next && buf1.st_mtime - buf2.st_mtime < 0)
		{
			tmp = clist->tmp;
			clist->tmp = clist->next->tmp;
			clist->next->tmp = tmp;
			loop = 1;
		}
		if (loop == 1)
			clist = head;
		else
			clist = clist->next;
	}
	return (head);
}

t_clist				*remove_last(t_clist *head)
{
	t_clist			*tclist;

	tclist = head;
	while (tclist->next->next)
		tclist = tclist->next;
	free(tclist->next);
	tclist->next = NULL;
	return (head);
}

void				print_basic_dir(char *dir, t_global *global)
{
	DIR				*dirp;
	struct dirent	*tmp;
	t_clist			*tclist;
	t_clist			*head;

	if (!(dirp = opendir(dir)))
		return (custom_error(dir, 0));
	tclist = create_clist();
	head = tclist;
	while ((tmp = readdir(dirp)))
		tclist = add_elem_clist(tclist, tmp->d_name);
	head = remove_last(head);
	if (global->t == 1)
		head = sort_time_clist(head);
	else
		head = sort_clist(head);
	if (global->r == 1)
		print_rclist(head, global);
	else
		print_clist(head, global);
	closedir(dirp);
}
