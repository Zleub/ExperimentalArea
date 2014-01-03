/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/03 14:14:53 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int     voir_touche()
{
  char     buffer[3];

  while (1)
  {
    read(0, buffer, 3);
    ft_printf("%s\n", buffer);
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


	static char term_buffer[2048];
	int success;
	int	check;
	char buffer[3];

	char *test;
	char *area;

	void *ptr;
	ptr = &(ft_putschar);


	struct termios term;

	// buffer = (char *)malloc(ft_strlen(term_buffer));
	// buffer = NULL;
	ft_printf("\n%s\n", getenv("TERM"));

	termtype = getenv("TERM");

	success = tgetent(term_buffer, termtype);
	ft_printf("%d\n", success);


	tcgetattr(0, &term);

	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées s'inscriront dans le terminal
	term.c_lflag &= ISIG;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSANOW, &term) == -1)
		ft_printf("bouze");

	// ft_printf("%d", MAX_INPUT);
	test = tgetstr("nl", &area);
	check = tputs(area, 1, ptr);

	// if (read(0, &buffer, 1) > 0)
	// {
	// 	if (buffer[0] == '\n')
	// 	{
	// 		test = tgetstr("/R", &area);
	// 		check = tputs(area, 1, ptr);
	// 	}
	// }
	// read(0, &buffer, 3);

	while(42)
	{
		ft_strclr(buffer);
		read(0, &buffer, 3);
		ft_printf("%d%d%d\n", buffer[0], buffer[1], buffer[2]);
	}
	// ft_printf("\n%d", tgetnum("li"));

	// test_();

	// ft_printf("%d\n", check);
	return (0);
}
