/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/22 14:13:44 by adebray          ###   ########.fr       */
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

	ft_printf("Test 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("hello %s %c", "world", 'A');
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("hello %s %c", "world", 'A');
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

	ft_putendl(NULL);
	ft_putendl("Da %x test");
	ft_putendl(NULL);

	ft_printf("Test 9 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", (unsigned int)4294967295);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", (unsigned int)4294967295);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", 42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", 42);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 3\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -42);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -42);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -429496729);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -429496729);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 5\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", (unsigned int)429496729795);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", (unsigned int)429496729795);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 5 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", (unsigned int)429496729796);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", (unsigned int)429496729796);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", 0);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", 0);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -0);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -0);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 7\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", 01);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", 01);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 8\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -01);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -01);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 9\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", 8);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", 8);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 10\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -9);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -9);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 11\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -1);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 12\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", 16);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", 16);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 13\n");
	ft_putstr("   My : ");
	ret = ft_printf("%x", -16);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", -16);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 14\n");
	ft_putstr("   My : ");
	int		i = -1;
	ret = ft_printf("%x", i);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%x", i);
	printf("%10d\n", ret);

	ft_printf("Test 9 - 15\n");
	ft_putstr("   My : ");
	ret = ft_printf("%X", 195);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%X", 195);
	printf("%10d\n", ret);

	ft_putendl(NULL);
	ft_putendl("Da %p test");
	ft_putendl(NULL);

	ft_printf("Test 10 - 1\n");
	char *to_del1 = "hello";
	ft_putstr("   My : ");
	ret = ft_printf("%p", to_del1);
	printf("%10d\n", ret);
	char *to_del2 = "hello";
	ft_putstr("Their : ");
	ret = printf("%p", to_del1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &to_del1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &to_del1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 3\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &to_del2);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &to_del2);
	printf("%10d\n", ret);

	int to_dell1 = 11112;
	int to_dell2 = 11112;

	int *del1 = &to_dell1;
	int *del2 = &to_dell2;

	ft_printf("Test 10 - 4\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", del1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", del1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 5\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &del1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &del1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &del2);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &del2);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 5\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &to_dell1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &to_dell1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 6\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &to_dell2);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &to_dell2);
	printf("%10d\n", ret);

	void *tmp1 = &to_del1;
	void *tmp2 = &to_del2;

	ft_printf("Test 10 - 7\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", tmp1);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", tmp1);
	printf("%10d\n", ret);

	ft_printf("Test 10 - 8\n");
	ft_putstr("   My : ");
	ret = ft_printf("%p", &tmp2);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%p", &tmp2);
	printf("%10d\n", ret);

	// ft_printf("Test 10 - 3\n");
	// ft_putstr("   My : ");
	// ret = ft_printf("%p", &(*to_del1));
	// printf("%10d\n", ret);
	// ft_putstr("Their : ");
	// ret = printf("%p", &(*to_del2));
	// printf("%10d\n", ret);

	// ft_printf("Test 10 - 4\n");
	// ft_putstr("   My : ");
	// ret = ft_printf("%p", &to_del1);
	// printf("%10d\n", ret);
	// ft_putstr("Their : ");
	// ret = printf("%p", &to_del2);
	// printf("%10d\n", ret);


	ft_printf("Test 11 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%%");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%%");
	printf("%10d\n", ret);

	ft_printf("Test 11 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("Hello %% World");
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("Hello %% World");
	printf("%10d\n", ret);

	ssize_t prout = 2244;
	// ssize_t prout2 = 666;

	ft_printf("Test 12 - 1\n");
	ft_putstr("   My : ");
	ret = ft_printf("%Zuft", prout);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("%Zuft", prout);
	printf("%10d\n", ret);

	ft_printf("Test 12 - 2\n");
	ft_putstr("   My : ");
	ret = ft_printf("Hello %Zd World", prout);
	printf("%10d\n", ret);
	ft_putstr("Their : ");
	ret = printf("Hello %Zd World", prout);
	printf("%10d\n", ret);

	// ft_printf("Test 13 - 1\n");
	// ft_putstr("   My : ");
	// ret = ft_printf("%");
	// printf("%10d\n", ret);
	// ft_putstr("Their : ");
	// ret = printf("%");
	// printf("%10d\n", ret);

	// ft_printf("Test 13 - 2\n");
	// ft_putstr("   My : ");
	// ret = ft_printf("Hello % World");
	// printf("%10d\n", ret);
	// ft_putstr("Their : ");
	// ret = printf("Hello % World");
	// printf("%10d\n", ret);

	// while (get_next_line(0, &tmp))
	// 	if (tmp[0] == 'q')
	// 		break;

	return (0);
}
