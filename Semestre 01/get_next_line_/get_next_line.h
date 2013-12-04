/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:21:56 by Arno              #+#    #+#             */
/*   Updated: 2013/12/03 16:34:45 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

int 	get_next_line(int const fd, char ** line);
#endif
