/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 01:04:28 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int const fd, char ** line)
{
	t_chain 	*toy_boy;

	toy_boy = malloc(sizeof(t_chain));
	read(fd, toy_boy->stomach, BUFF_SIZE);
	return (0);
}
