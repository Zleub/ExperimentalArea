/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:12:01 by adebray           #+#    #+#             */
/*   Updated: 2014/02/02 16:06:38 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh3.h>

#include <fcntl.h>
#define TERMINALS "abcdefghijklmnopqrstuvwxyz"

int							tswitch(int i)
{
	struct termios			term;
	static struct termios	save;

	if (i == 1)
	{
		if (tgetent(0, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		save = term;
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
		tcsetattr(0, 0, &term);
		return (0);
	}
	else
	{
		tcsetattr(0, 0, &save);
		return (0);
	}
}

void		is_lang(char *c)
{
	int		i;
	char	*lang;

	i = 0;
	lang = TERMINALS;
	while (lang[i])
	{
		if (*c == lang[i])
		{
			ft_printf("%c", *c);
		}
		i += 1;
	}
}

int			test(void)
{
	char	str[4] = {0};

	if(tswitch(1) == -1)
		return (-1);
	while (read(0, str, 3))
	{
		ft_printf("%d%d%d%d\n", str[0], str[1], str[2], str[3]);
		ft_striter(str, &is_lang);
		ft_printf("\n");
		ft_strclr(str);
	}
	tswitch(0);
	return (0);
}

char		*ft_mstrcat(char *str_1, char *str_2)
{
	char	*ret;
	char	*p;

	ret = (char *)malloc(ft_strlen(str_1) + ft_strlen(str_2) + 1);
	p = ret;
	while (*str_1)
		*ret++ = *str_1++;
	while (*str_2)
		*ret++ = *str_2++;
	*ret = '\0';
	return (p);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	else
		while (n-- && s1[i] != '\0')
		{
			dup[i] = s1[i];
			i = i + 1;
		}
		dup[i] = '\0';
	return (dup);
}

t_tree		**function_to_create_leaf_child_node(t_tree *tree)
{

}

int			main(void)
{
	int		fd;
	int		i;
	int		start;
	char	*tmp;
	t_gnl	*head;
	t_gnl	*gnl;

	t_tree	*tree;
	t_tree	*tree_head;

	if ((fd = open("test.gmr", O_RDONLY)) < 0)
		return (-1);

	start = 1;
	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	head = gnl;
	tree = (t_tree*)malloc(sizeof(t_tree));
	tree_head = tree;
	while (get_next_line(fd, &tmp) > 0)
	{
		if (tmp[0] != '\t')
		{
			if (!start)
			{
				gnl->next = (t_gnl*)malloc(sizeof(t_gnl));
				gnl = gnl->next;
				gnl->next = NULL;

				/* CAREFUL TO REALLOC HERE ONCE LEAF / CHILD NODE CREATED */
				tree->next = (t_tree**)malloc(sizeof(t_tree*));
				tree->next[0] = (t_tree*)malloc(sizeof(t_tree));
				tree = tree->next[0];
				tree->next[0] = NULL;
			}
			gnl->str = ft_strdup(tmp);

			tree->type = NODE;
			tree->status = ONCE;

			i = 0;
			while (ft_isalpha(tmp[i]))
				i += 1;
			tree->str = ft_strndup(tmp, i);

			tree->next = function_to_create_leaf_child_node(tree, tmp);



			ft_printf("type : %d, status : %d, str : %s - %p\n", tree->type, tree->status, tree->str, tree);

			start = 0;
		}
		else
		{
			i = 0;
			while (tmp[i] == '\t')
				i += 1;
			tmp = ft_strsub(tmp, i, ft_strlen(tmp) - i);
			// ft_printf("tmp : %s\n", tmp);
			gnl->str = ft_mstrcat(gnl->str, tmp);
		}
	}

	// gnl = head;
	// i = 0;
	// while(gnl)
	// {
	// 	ft_printf("%d dump : %s\n", i, gnl->str);
	// 	gnl = gnl->next;
	// 	i += 1;
	// }
	return (0);
}

// int			main(void)
// {
// 	char un = 'a';
// 	char *deux = "Hello World";
// 	ft_printf("sizeof(un) = %d, sizeof(deux) = %d", sizeof(un), sizeof(deux));
// 	return (0);
// }
