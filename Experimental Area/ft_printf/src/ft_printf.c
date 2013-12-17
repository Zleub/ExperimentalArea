/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:17:41 by adebray           #+#    #+#             */
/*   Updated: 2013/12/17 10:47:21 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_printf(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, fmt);
	while (*fmt)
		switch(*fmt++) {
			case 's':			   /* string */
			s = va_arg(ap, char *);
			printf("string %s\n", s);
			break;
			case 'd':			   /* int */
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
			case 'c':			   /* char */
				/* Note: char is promoted to int. */
			c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
		va_end(ap);
	}
