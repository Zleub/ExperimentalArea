/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/01/04 18:13:31 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <ft_printf.h>
# include <gnl.h>
# include <libft.h>

# include <stdlib.h>

# include <curses.h>
# include <term.h>
# include <termcap.h>

int		ft_putschar(int c);

typedef struct		s_list
{
	char			*str;
	int				len;
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

typedef struct		s_term
{
	int				height;
	int				width;
	int				maxlen;
	int				maxcol;
	int				clist;
	int				maxlin;
}					t_term;

#endif
