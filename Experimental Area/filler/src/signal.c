/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:26:47 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:23:02 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void			resize(int sig)
{
	(void)sig;
	tgetent(0, getenv("TERM"));
	tputs(tgetstr("cl", NULL), 1, ft_putschar);
	so_printed(NULL);
	print_cursor(NULL);
}

static void			continu(int sig)
{
	(void)sig;
	tswitch(1);
	tputs(tgetstr("ti", NULL), 1, ft_putschar);
	tputs(tgetstr("vi", NULL), 1, ft_putschar);
	signal(SIGTSTP, termstop);
	so_printed(NULL);
	print_cursor(NULL);
}

void				termstop(int sig)
{
	struct termios	term;
	char			cp[2];

	(void)sig;
	if (tcgetattr(0, &term) == -1)
		return ;
	cp[0] = term.c_cc[VSUSP];
	cp[1] = 0;
	tputs(tgetstr("ve", NULL), 1, ft_putschar);
	tputs(tgetstr("te", NULL), 1, ft_putschar);
	tswitch(0);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, continu);
	ioctl(0, TIOCSTI, cp);
}

static void			_quit(int sig)
{
	(void)sig;
	tputs(tgetstr("ve", NULL), 1, ft_putschar);
	tputs(tgetstr("te", NULL), 1, ft_putschar);
	tswitch(0);
	exit(sig);
}

void				_signal(void)
{
	void			(*array[4])(int) = {resize, termstop, continu, _quit};

	signal(SIGWINCH, array[SIG_WINCH]);
	signal(SIGTSTP, array[SIG_TSTP]);
	signal(SIGCONT, array[SIG_CONT]);
	signal(SIGINT, array[SIG_INT]);
}
