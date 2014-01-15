/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/01/15 11:59:46 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define SHEUM "i) {i -= 1; if (i == 0"

# include <ft_printf.h>
# include <gnl.h>
# include <libft.h>

// # include <stdlib.h>

// # include <curses.h>
// # include <term.h>
// # include <termcap.h>

// # include <signal.h>
// # include <sys/ioctl.h>
// # include <ft_select.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_coord
{
	int				*size;
	int				*piece;
}					t_coord;

#endif
