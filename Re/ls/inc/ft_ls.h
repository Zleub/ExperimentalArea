/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 03:39:26 by adebray           #+#    #+#             */
/*   Updated: 2014/04/15 22:32:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_printf.h>

# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct		s_global
{
	int				nb_dir;
	int				a;
	int				t;
	int				r;
}					t_global;

typedef struct		s_tmp
{
	struct dirent	*tmp;
	struct s_tmp	*next;
}					t_tmp;

typedef struct		s_clist
{
	char			*tmp;
	struct s_clist	*next;
	struct s_clist	*prev;
}					t_clist;

void				print_dir(char *dir, t_global *global);
char				**sort_array(char **array);
void				add_to_array(char **array, char *str);
void				print_dir_list(char **array, t_global *global);
void				print_nodir_list(char **array, t_global *global);
t_global			*create_global(void);
t_clist				*create_clist(void);
void				print_clist(t_clist *head, t_global *global);
void				print_global(t_global *new_global);
t_clist				*sort_clist(t_clist *head);
t_clist				*remove_last(t_clist *head);
void				print_basic_dir(char *dir, t_global *global);
void				custom_error(char *dir, int check);
int					get_array_size(char **array);
char				**ft_malloc(int argc);
void				print_rclist(t_clist *head, t_global *global);
t_clist				*add_elem_clist(t_clist *tclist, char *str);
char				**reverse_array(char **array);
void				illegal_argument(char c);
void				print_nofile_list(char **array, t_global *global);

#endif
