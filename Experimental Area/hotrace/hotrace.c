/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:32:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/14 03:35:35 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void          *lst_init(t_elem *elem)
{
    elem = malloc(sizeof(t_elem));
    if (elem)
    {
        elem->keyword = NULL;
        elem->value = NULL;
        elem->next = NULL;
    }
    return (elem);
}

static t_elem   *fpush(t_elem *lst_elem)
{
    t_elem      *new_elem;

    new_elem = malloc(sizeof(t_elem));
    if (new_elem)
    {
        new_elem->keyword = NULL;
        new_elem->value = NULL;
        new_elem->next = lst_elem;
    }
    return (new_elem);
}

static void     get_elem(t_elem *lst_elem)
{
    // t_elem      *tmp;
    char        *line;
    int         i;

    i = 0;
    // tmp = tls_elem;
    while (get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
    {
        if (i % 2 == 0)
            lst_elem->keyword = line;
        else if (i % 2 == 1)
            lst_elem->value = line;
        lst_elem = fpush(lst_elem);
    }
    return ;
}

#include <stdio.h>
void            print_list(t_elem *lst_elem)
{
    t_elem      *cursor;
    int         i;

    i = 1;
    cursor = lst_elem;
    while (cursor->next != NULL)
    {
        printf("Case %d\n\nKeyword <%s>\nValue <%s>\n\n\n", i++, cursor->keyword, cursor->value);
        cursor = cursor->next;
    }
}

int             main(void)
{
    t_elem      *lst_elem;

    lst_elem = NULL;
    lst_init(lst_elem);
    get_elem(lst_elem);
    print_list(lst_elem);
    // while(!getnextlineisblank)


    return (0);
}

