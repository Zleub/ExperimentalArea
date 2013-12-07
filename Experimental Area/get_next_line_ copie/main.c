/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 05:58:35 by adebray           #+#    #+#             */
/*   Updated: 2013/12/07 05:58:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int                main(void)
{
    int            i;
    char        *s;

    i = 0;
    s = NULL;
    while (get_next_line(0, &s))
    {
        printf("%d : %s$\n", ++i, s);
        free(s);
    }
    return (0);
}
