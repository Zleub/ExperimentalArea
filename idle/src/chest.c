/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 05:50:25 by adebray           #+#    #+#             */
/*   Updated: 2013/12/19 06:03:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>
#include <gnl.h>
#include <libft.h>

int						ft_chest_0(void)
{
	char				**prout;
	int					i;
	int					fd;

	i = -1;
	prout = malloc(sizeof(char*) * 25);
	while (++i < 25)
		prout[i] = NULL;
	fd = open("./res/monsters.txt", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &prout[i]))
		i = i + 1;
	prout[i] = NULL;
	while(*prout)
		ft_putendl(*prout++);
	close (fd);
	return (0);
}
