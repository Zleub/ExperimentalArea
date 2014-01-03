/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/03 01:34:10 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int     voir_touche()
{
  char     buffer[3];

  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
      printf("C'est une fleche !\n");
    else if (buffer[0] == 4)
    {
      printf("Ctlr+d, on quitte !\n");
      return (0);
    }
  }
  return (0);
}


int              test_(void)
{
  char           *name_term;
  struct termios term;

  if ((name_term = getenv("TERM")) == NULL)
     return (-1);
  if (tgetent(NULL, name_term) == ERR)
     return (-1);
  // remplis la structure termios des possibilités du terminal.
  if (tcgetattr(0, &term) == -1)
     return (-1);
  voir_touche();
return (0);
}

int					main(void)
{
	char *termtype;


	char term_buffer[2048];
	int success;
	int	check;
	char *buffer;

	char *test;
	char *area;

	void *ptr;
	ptr = &(ft_putschar);


	buffer = (char *)malloc(ft_strlen(term_buffer));
	// buffer = NULL;
	ft_printf("\n%s\n", getenv("TERM"));

	termtype = getenv("TERM");

	success = tgetent(0, termtype);
	ft_printf("%d\n", success);


	test = tgetstr("cl", &area);
	check = tputs(area, 1, ptr);

	ft_printf("\n%d", tgetnum("co"));

	test_();

	// ft_printf("%d\n", check);
	return (0);
}
