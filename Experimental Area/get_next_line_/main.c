/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 01:04:12 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 10:16:03 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"

int 	main(void)
{
	int 	fd;
	int 	i;
//	int 	test;
	char	*str;

	i = 0;
	str = NULL;
	fd = open("./test.txt", O_RDONLY);
	// while ((test = get_next_line(fd, &str)) != 0)
	// {
	// 	ft_putnbr(i);
	// 	ft_putstr(" : main dump : ");
	// 	ft_putstr(str);
	// 	ft_putstr(" | ");
	// 	ft_putnbr(test);
	// 	ft_putendl("");
	// 	i = i + 1;
	// }
	i = get_next_line(fd, &str);
	ft_putstr("main dump : ");
	ft_putstr(str);
	ft_putstr(" | ");
	ft_putstr("return : ");
	ft_putnbr(i);
	ft_putendl("");
	free(str);

	// i = get_next_line(fd, &str);
	// ft_putstr("main dump : ");
	// ft_putstr(str);
	// ft_putstr(" | ");
	// ft_putstr("return : ");
	// ft_putnbr(i);
	// ft_putendl("");

	close(fd);
	return (0);
}

// #include <stdio.h>
// int                main(void)
// {
//     int            i;
//     char        *s;

//     i = 0;
//     s = NULL;
//     while (get_next_line(0, &s))
//     {
//         printf("%d : %s$\n", ++i, s);
//         free(s);
//     }
//     return (0);
// }
