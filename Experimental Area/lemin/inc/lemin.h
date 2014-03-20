/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:41:20 by adebray           #+#    #+#             */
/*   Updated: 2014/03/20 16:10:25 by adebray          ###   ########.fr       */
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

typedef struct		s_room
{
	char			*str;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	char			*src;
	struct s_pipe	*next;
	struct s_pipe	*child;
}					t_pipe;

int		get_lemin_nb(void);
t_data	*create_data(void);
void	print_data(t_data *head);
t_gnl	*create_gnl(void);
void	print_gnl(t_gnl *head);
t_pipe	*create_pipe(void);
void	print_pipe(t_pipe *head, int c);
t_room	*create_room(void);
void	print_room(t_room *head);
int		is_room(char *str);
int		is_pipe(char *str);
char	*get_room(char *tmp);
void	get_start(t_data *data, t_room **head, t_room *room_tmp);
void	get_end(t_data *data, t_room **head, t_room *room_tmp);
void	start_end(char *str, t_data *data, t_room **head);

#endif
