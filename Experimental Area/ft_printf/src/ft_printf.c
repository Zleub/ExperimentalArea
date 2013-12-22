/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:17:41 by adebray           #+#    #+#             */
/*   Updated: 2013/12/22 08:16:27 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

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
	int						d;
	void					*tmp;
	unsigned int			u;
	char					*s;
	unsigned long int		ul;

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
		u = va_arg(ap, unsigned long int);
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
		tmp = va_arg(ap, void*);
		ul = (unsigned long int)tmp;
		flags->cmp += ft_printf("%s", "0x");
		// flags->cmp += ft_printf("%x", ul/4294967295);
		flags->cmp += ft_printf("%x", ul);
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
