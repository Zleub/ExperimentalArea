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

t_flag		*flags_init(t_flag *flags)
{
	flags = malloc(sizeof(t_flag));
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	return (flags);	
}

t_flag		*parse_option(t_flag *flags, char *str)
{
	if (!flags)
		flags = flags_init(flags);
	if (*str == '-')
		flags->minus = 1;
	else if (*str == ' ')
		flags->space = 1;
	return (flags);		
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	static	t_flag	*flags;
//	char		out;
	int		ret;

	va_start(ap, str);
	ret = 0;
	flags = NULL;
	while (*str)
	{
		if (*str != '%')
		{ 
			ft_putchar(*str);
			ret += 1;
		}
		else
		{
			str += 1;
			while (!ft_isdigit(*str))
			{
				flags = parse_option(flags, str);
				str += 1;
			}
			ft_putnbr(flags->space);
//			print_arguments();
		}
		str++;
	}
	va_end(ap);
	return (ret);
}	





/*{
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
}*/




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
