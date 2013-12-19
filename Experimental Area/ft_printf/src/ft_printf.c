/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:17:41 by adebray           #+#    #+#             */
/*   Updated: 2013/12/18 23:13:49 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

char	*ft_cutstring(char *from, char *to)
{
	char	*str;

	str = malloc(sizeof(char) * 10);
	while (&from != &to)
	{
		*str++ = *from++;
	}
	return (str);
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	int			d;
	int			cmp;
	int			i;
	char		*s;

	va_start(ap, str);
	cmp = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			cmp += 1;
		}
		else
		{
			str++;
			i = 0;
			while (ft_isdigit(ft_atoi(str)))
			{
				i = i + 1;
			}
			if (*str == 's')
			{
				s = va_arg(ap, char*);
				// if (i)
				// {
				// 	;
				// }
				if(s == NULL)
				{
					cmp += ft_printf("(null)");
				}
				else
					ft_putstr(s);
				cmp += ft_strlen(s);
			}
			else if (*str == 'c')
			{
				d = va_arg(ap, int);
				ft_putchar(d);
				cmp += 1;
			}
			else if (*str == 'd' || *str == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				cmp += ft_strlen(ft_itoa(d));
			}
		}
		str++;
	}
	va_end(ap);
	return (cmp);
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
