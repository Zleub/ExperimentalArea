/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/18 15:55:08 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <gnl.h>
#include <libft.h>
#include <stdio.h>

int		main(void)
{
	ft_printf("Test 1\n");
	ft_printf("my : hello %s\n", "world");
	printf("their : hello %s\n", "world");
	ft_printf("Test 2-1\n");
	ft_printf("my : hello %s !\n", "world");
	printf("their : hello %s !\n", "world");
	ft_printf("Test 2-2\n");
	ft_printf("my : hello %7s !\n", "world");
	printf("their : hello %7s !\n", "world");
	ft_printf("Test 3\n");
	ft_printf("my : %c\n", '!');
	printf("their : %c\n", '!');
	ft_printf("Test 4\n");
	ft_printf("my : hello %s %c\n", "world", '!');
	printf("their : hello %s %c\n", "world", '!');
	ft_printf("Test 5\n");
	ft_printf("my : %d\n", 42);
	printf("their : %d\n", 42);
	return (0);
}
