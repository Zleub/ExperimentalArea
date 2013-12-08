/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 05:14:53 by adebray           #+#    #+#             */
/*   Updated: 2013/12/08 00:59:02 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 128

int 	get_next_line(int const fd, char ** line);
#endif
