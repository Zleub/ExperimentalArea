/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/28 15:08:15 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDLE_H
# define IDLE_H
# define LIFE int h_life, int m_life

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

#include <ft_printf.h>
#include <errno.h>

#include <gnl.h>
#include <libft.h>

typedef struct	s_heros
{
	char		*name;
	int			strengh;
	int			defense;
}				t_heros;

void				hello(void);
unsigned int		hashich(char *line);
int					ft_fibonacci(int index);
void				print_heros(t_heros *heros);
char				*trim_save(char *save_name);
char				*get_name(void);
int					get_rand(int modulo);
t_heros				*create_monster(void);
void				give_info(t_heros *heros, t_heros *monster, int i, LIFE);
int					playing(t_heros *heros, int h_life, int m_life);


#endif
