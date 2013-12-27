/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/27 10:09:03 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>
#include <ft_printf.h>

int			main(void)
{
	char			*str;
	// extern char		**environ;

	while (!str || str[0] != 'q')
	{
		ft_printf("->");
		if (get_next_line(0, &str) > 0)
		{
			ft_printf("%s\n", str);
			if (str[0] != 'q')
			{
				free(str);
				str = NULL;
			}
		}
	}
	return (0);
}
