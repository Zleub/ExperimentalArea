/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:21:56 by Arno              #+#    #+#             */
/*   Updated: 2013/12/04 02:30:43 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int const fd, char ** line)
{
	char	buffer[BUFF_SIZE];

	read(fd, buffer, BUFF_SIZE);

	*line = buffer;
	return (0);
}
