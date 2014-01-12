/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:17:36 by adebray          ###   ########.fr       */
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

# include <signal.h>
# include <sys/ioctl.h>
# include <ft_select.h>
# include <fcntl.h>

# define KEYUP read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 65
# define KEYDW read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 66
# define KEYRT read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 67
# define KEYLF read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 68
# define KEYSUP read_char[0] == 126 && read_char[1] == 0
# define KEYDEL read_char[0] == 127 && read_char[1] == 0
# define XY list->x, list->y % tmp->height

typedef enum	e_sig
{
	SIG_WINCH, SIG_TSTP, SIG_CONT, SIG_INT
}				t_sig;

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
	int				col_nb;
	int				col_size;
	int				li_nb;
	int				li_by_col;
	t_list			*col;
	struct s_term	*next;
	struct s_term	*prev;
}					t_term;

int					ft_putschar(int c);
void				termstop(int sig);
t_term				*build_crown(t_list *head);
t_list				*so_printed(t_list *head);
void				print_cursor(t_list *head);
int					tswitch(int i);
t_list				*build_list(int argc, char **argv);
void				_signal(void);
int					read_user(t_list *head);

#endif
