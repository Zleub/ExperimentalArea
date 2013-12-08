/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 07:39:17 by adebray           #+#    #+#             */
/*   Updated: 2013/12/08 07:41:06 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 128

int 	get_next_line(int const fd, char ** line);
char	*ft_strnjoin(char const *s1, char const *s2, int n);

#endif
