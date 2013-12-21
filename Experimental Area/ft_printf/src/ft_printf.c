/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:17:41 by adebray           #+#    #+#             */
/*   Updated: 2013/12/21 20:29:52 by adebray          ###   ########.fr       */
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

t_flags		*flags_init(t_flags *flags)
{
	flags = malloc(sizeof(t_flags));
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	return (flags);
}

void	get_flags(t_flags *flags, char *str)
{
	if (*str == '-')
		flags->minus = 1;
	else if (*str == '0')
		flags->zero = 1;
	else if (*str == '+')
		flags->plus = 1;
	else if (*str == ' ')
		flags->space = 1;
}

int		ft_isflags(char str)
{
	if (str == '-' || str == '0' || str == '+' || str == ' ')
		return (1);
	else
		return (0);
}

void	get_width(t_flags *flags, char str)
{
	flags->width *= 10;
	flags->width += str - '0';
}

void	print_arguments(char ar, t_flags *flags, va_list ap)
{
	int				d;
	unsigned int	u;
	char			*s;
	// void			*p;

	unsigned long int				test;

	if (ar == 'd' || ar == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		flags->cmp += ft_strlen(ft_itoa(d));
	}
	else if (ar == 'u')
	{
		u = va_arg(ap, unsigned int);
		if (u > 9)
		{
			flags->cmp += ft_printf("%d", u / 10);
		}
		flags->cmp += ft_printf("%d", u % 10);
	}
	else if (ar == 'o')
	{
		u = va_arg(ap, unsigned int);
		flags->cmp += ft_putoctal(u);
	}
	else if (ar == 'X')
	{
		u = va_arg(ap, unsigned int);
		flags->cmp += ft_put_sheum_hexa(u);
	}
	else if (ar == 'x')
	{
		u = va_arg(ap, unsigned int);
		flags->cmp += ft_puthexa(u);
	}
	else if (ar == 'c')
	{
		d = va_arg(ap, int);
		ft_putchar(d);
		flags->cmp += 1;
	}
	else if (ar == 's')
	{
		s = va_arg(ap, char*);
		if (s == NULL)
		{
			flags->cmp += ft_printf("(null)");
		}
		else
			ft_putstr(s);
		flags->cmp += ft_strlen(s);
	}
	else if (ar == 'p')
	{
		test = va_arg(ap, unsigned long int);
		// test = (int)&p;
		ft_printf("%x", test);
	}
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_flags	*flags;

	va_start(ap, str);
	flags = flags_init(flags);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			flags->cmp += 1;
		}
		else
		{
			str += 1;
			while (ft_isflags(*str))
			{
				get_flags(flags, str);
				str += 1;
			}
			while (ft_isdigit(*str))
			{
				get_width(flags, *str);
				str += 1;
			}
			print_arguments(*str, flags, ap);
		}
		str++;
	}
	va_end(ap);
	return (flags->cmp);
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
