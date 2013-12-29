/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:19:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:38:01 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_1_H
# define MINISHELL_1_H

# include <dirent.h>
# include <libft.h>
# include <gnl.h>
# include <ft_printf.h>

typedef struct			s_binlist
{
	char				*name;
	char				*path;
	struct s_binlist	*next;
}						t_binlist;

typedef struct			s_vars
{
	t_binlist			**binlist;
	char				*shell;
}						t_vars;

char					**ft_strcsplit(char const *s, char c, int start);
int						get_path(char **environ);
char					*get_shell(char **environ);
t_binlist				*binlist_init(void);
void					ft_printshackle(t_binlist *shackle);
void					ft_dumpbinlist(t_binlist **head);


#endif
