/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:31:57 by adebray           #+#    #+#             */
/*   Updated: 2013/12/14 03:35:56 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>

typedef struct      s_elem
{
    char            *keyword;
    char            *value;
    struct s_elem   *next;
}                   t_elem;
