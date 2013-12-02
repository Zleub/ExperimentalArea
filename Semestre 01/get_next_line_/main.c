/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/02 07:04:50 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int 	main(int argc, char **argv)
{
	int 	i;

	i = 0;
	ft_putnbr(argc - 1);
	ft_putendl(" arguments.");
	while (i <= argc - 1)
	{
		ft_putendl(argv[i]);
		i = i + 1;
		catch_argument;
	}
	return (0);
}
