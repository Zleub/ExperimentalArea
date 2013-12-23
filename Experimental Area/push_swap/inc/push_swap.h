/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 04:36:24 by adebray           #+#    #+#             */
/*   Updated: 2013/12/23 07:16:58 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_list
{
	int			data;
	void		*next;
}				t_list;

void		ft_printargv(int argc, char **argv);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);


#endif
