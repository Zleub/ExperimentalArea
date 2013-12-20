/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/18 23:01:46 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <gnl.h>
#include <libft.h>
#include <stdio.h>

int		main(void)
{
	char	*tmp;
	// char	*test;
	int		ret;

	// tmp = malloc(sizeof(char) * 10);

	// ret = 3;

	// test = ft_cutstring(&tmp[3], &tmp[5]);

	// ft_putendl(test);


	ft_printf("Test 1\n");
	ft_putstr("My : ");
	ret = ft_printf("hello % s", "world");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-1\n");
	ft_putstr("My : ");
	ret = ft_printf("hello %s !", "world");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s !", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-2\n");
	ft_putstr("My : ");
	ret = ft_printf("hello %7s !", "world");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %7s !", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-3\n");
	ft_putstr("My : ");
	tmp = NULL;
	ret = ft_printf("hello %s !", tmp);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	tmp = NULL;
	ret = printf("hello %s !", tmp);
	printf("%10d\n", ret);
	ft_printf("Test 3\n");
	ft_putstr("My : ");
	ret = ft_printf("%c", '!');
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%c", '!');
	printf("%10d\n", ret);
	ft_printf("Test 4\n");
	ft_putstr("My : ");
	ret = ft_printf("hello %s %c", "world", '!');
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s %c", "world", '!');
	printf("%10d\n", ret);
	ft_printf("Test 5 - 1\n");
	ft_putstr("My : ");
	ret = ft_printf("%d", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%d", 42);
	printf("%10d\n", ret);
	ft_printf("Test 5 - 2\n");
	ft_putstr("My : ");
	ret = ft_printf("%d", 2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%d", 2147483647);
	printf("%10d\n", ret);
	ft_printf("Test 5 - 3\n");
	ft_putstr("My : ");
	ret = ft_printf("%d", -2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%d", -2147483647);
	printf("%10d\n", ret);
	ft_printf("Test 5 - 4\n");
	ft_putstr("My : ");
	ret = ft_printf("%10d", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%10d", 42);
	printf("%10d\n", ret);
	ft_printf("Test 6 - 1\n");
	ft_putstr("My : ");
	ret = ft_printf("%i", 2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%i", 2147483647);
	printf("%10d\n", ret);
	ft_printf("Test 6 - 2\n");
	ft_putstr("My : ");
	ret = ft_printf("%i", -2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%i", -2147483647);
	printf("%10d\n", ret);

	while (get_next_line(0, &tmp))
		if (tmp[0] == 'q')
			break;
	return (0);
}
