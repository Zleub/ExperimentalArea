/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/18 22:50:49 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct	s_flag
{
	char	minus;
	char	plus;
	char	zero;
	char	space;
	int	width;
}		t_flag;

int			ft_printf(char *str, ...);
void		ft_putstr(char const *s);
void		ft_putnbr(int n);
void		ft_putchar(char c);
size_t		ft_strlen(const char *s);
char		*ft_itoa(int n);
char		*ft_cutstring(char *from, char *to);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif
