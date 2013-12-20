/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/20 17:57:38 by adebray          ###   ########.fr       */
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
	ft_putstr("   My : ");
	ret = ft_printf("hello %s", "world");
	printf("% 10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-1\n");
	ft_putstr("   My : ");
	ret = ft_printf("hello %s !", "world");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s !", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-2\n");
	ft_putstr("   My : ");
	ret = ft_printf("hello %7s !", "world");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %7s !", "world");
	printf("%10d\n", ret);
	ft_printf("Test 2-3\n");
	ft_putstr("   My : ");
	tmp = NULL;
	ret = ft_printf("hello %s !", tmp);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	tmp = NULL;
	ret = printf("hello %s !", tmp);
	printf("%10d\n", ret);
	ft_printf("Test 3\n");
	ft_putstr("   My : ");
	ret = ft_printf("%c", '!');
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%c", '!');
	printf("%10d\n", ret);
	ft_printf("Test 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("hello %s %c", "world", '!');
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s %c", "world", '!');
	printf("%10d\n", ret);

	ft_putendl(NULL);
	ft_putendl("Da %d test");
	ft_putendl(NULL);

	ft_printf("Test 5 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%d", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%d", 42);
	printf("%10d\n", ret);

	ft_printf("Entre-Test\n");
	ft_putstr("   My : ");
	ret = ft_printf("%-5d", -42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%-5d", -42);
	printf("%10d\n", ret);

	ft_printf("Test 5 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("%+d", 2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%+d", 2147483647);
	printf("%10d\n", ret);

	ft_printf("Test 5 - 3\n");
	ft_putstr("   My : ");
	ret = ft_printf("%d", (int)-2147483648);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%d", (int)-2147483648);
	printf("%10d\n", ret);

	ft_printf("Test 5 - 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("% 10d", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("<% 10d>", 42);
	printf("%10d\n", ret);

	ft_printf("Test 6 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%i", 2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%i", 2147483647);
	printf("%10d\n", ret);
	ft_printf("Test 6 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("%i", -2147483647);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%i", -2147483647);
	printf("%10d\n", ret);

	ft_putendl(NULL);
	ft_putendl("Da %u test");
	ft_putendl(NULL);

	ft_printf("Test 7 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%u", (unsigned int)4294967295);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%u", (unsigned int)4294967295);
	printf("%10d\n", ret);

	ft_putendl(NULL);
	ft_putendl("Da %o test");
	ft_putendl(NULL);

	ft_printf("Test 8 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", (unsigned int)4294967295);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", (unsigned int)4294967295);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 42);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 3\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -42);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -429496729);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -429496729);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 5\n");
	ft_putstr("   My : ");
	ft_printf("%u\n", (unsigned int)429496729795);
	ret = ft_printf("%o", (unsigned int)429496729795);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	printf("%u\n", (unsigned int)429496729795);
	ret = printf("%o", (unsigned int)429496729795);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 5 - 1\n");
	ft_putstr("   My : ");
	ft_printf("%u\n", (unsigned int)429496729796);
	ret = ft_printf("%o", (unsigned int)429496729796);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	printf("%u\n", (unsigned int)429496729796);
	ret = printf("%o", (unsigned int)429496729796);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 0);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 0);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -0);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -0);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 7\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 01);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 01);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 8\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -01);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -01);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 9\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 8);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 8);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 10\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -9);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -9);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 11\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -1);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 12\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 16);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 16);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 13\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", -16);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", -16);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 14\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 000000000000000000001);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 000000000000000000001);
	printf("%10d\n", ret);

	ft_printf("Test 8 - 15\n");
	ft_putstr("   My : ");
	ret = ft_printf("%o", 195);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%o", 195);
	printf("%10d\n", ret);


	// while (get_next_line(0, &tmp))
	// 	if (tmp[0] == 'q')
	// 		break;

	return (0);
}
