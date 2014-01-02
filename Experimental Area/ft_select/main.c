/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/03 00:48:41 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int					main(void)
{
	char *termtype;


	char term_buffer[2048];
	int success;
	int	check;
	char *buffer;

	char *test;
	char *area;

	void *ptr;
	ptr = &(ft_putschar);


	buffer = (char *)malloc(ft_strlen(term_buffer));

	ft_printf("\n%s\n", getenv("TERM"));

	termtype = getenv("TERM");

	success = tgetent(0, termtype);
	ft_printf("%d\n", success);


	test = tgetstr("cl", &area);
	check = tputs(area, 1, ptr);
	// ft_printf("%d\n", check);
	return (0);
}
