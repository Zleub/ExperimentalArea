/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/17 03:11:11 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDLE_H
# define IDLE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_heros
{
	char		*name;
	int			strengh;
	int			defense;
}				t_heros;

void				hello(void);
unsigned int		hashich(char *line);
int					ft_fibonacci(int index);

#endif
