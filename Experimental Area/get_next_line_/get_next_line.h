/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 00:03:13 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 13:02:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct 	s_chain
{
	char 		*stomach;
	void 		*grand_pa;
	void 		*pa;
	void 		*child;
}				t_chain;

int 	get_next_line(int const fd, char ** line);
#endif
