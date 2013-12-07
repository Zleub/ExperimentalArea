/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:32:46 by Arno              #+#    #+#             */
/*   Updated: 2013/12/07 05:14:53 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 80

int 	get_next_line(int const fd, char ** line);
#endif
