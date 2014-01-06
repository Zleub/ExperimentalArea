/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/01/06 09:39:36 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <ft_printf.h>
# include <gnl.h>
# include <libft.h>

# include <stdlib.h>

// # include <curses.h>
# include <term.h>
# include <termcap.h>

# define KEY_UP read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 65
# define KEY_DW read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 66
# define KEY_RT read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 67
# define KEY_LF read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 68


int		ft_putschar(int c);

typedef struct		s_list
{
	char			*str;
	char			slc;
	int				len;
	int				x;
	int				y;
	struct s_list	*next;
	struct s_list	*prev;
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
