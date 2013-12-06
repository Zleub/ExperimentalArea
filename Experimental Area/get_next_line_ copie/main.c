/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:32:46 by Arno              #+#    #+#             */
/*   Updated: 2013/12/06 02:08:12 by adebray          ###   ########.fr       */
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
