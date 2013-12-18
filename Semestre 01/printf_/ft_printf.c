/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:17:41 by adebray           #+#    #+#             */
/*   Updated: 2013/12/18 15:54:27 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_printf(char *str, ...)
{
	va_list		ap;
	int			d;
	char		*s;

	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
		else
		{
			str++;
			if (*str == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr(s);
			}
			else if (*str == 'c')
			{
				d = va_arg(ap, int);
				ft_putchar(d);
			}
			else if (*str == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
		}
		str++;
	}
}




		// switch(*fmt++) {
		// 	case 's':			   /* string */
		// 	s = va_arg(ap, char *);
		// 	ft_putstr;
		// 	break;
		// 	case 'd':			   /* int */
		// 	d = va_arg(ap, int);
		// 	printf("int %d\n", d);
		// 	break;
		// 	case 'c':			   /* char */
		// 		/* Note: char is promoted to int. */
		// 	c = va_arg(ap, int);
		// 	printf("char %c\n", c);
		// 	break;
		// }
		// va_end(ap);}
