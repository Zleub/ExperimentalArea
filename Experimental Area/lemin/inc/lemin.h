/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:41:20 by adebray           #+#    #+#             */
/*   Updated: 2014/03/02 10:11:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <gnl.h>

typedef struct	s_data
{
	char		*start;
	char		*end;
	int			room_nb;
	int			lemin_nb;
}				t_data;

typedef struct		s_gnl
{
	char			*str;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_pipe
{
	char			*src;
	struct s_pipe	**dst;
}					t_pipe;

#endif
