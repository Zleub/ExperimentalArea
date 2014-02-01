#include <ft_printf.h>
#include <gnl.h>
#include <stdlib.h>
#include <term.h>
#include <libft.h>

#define TERMINALS "abcdefghijklmnopqrstuvwxyz"

int							tswitch(int i)
{
	struct termios			term;
	static struct termios	save;

	if (i == 1)
	{
		if (tgetent(0, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		save = term;
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
		tcsetattr(0, 0, &term);
		return (0);
	}
	else
	{
		tcsetattr(0, 0, &save);
		return (0);
	}
}

void		is_lang(char *c)
{
	int		i;
	char	*lang;

	i = 0;
	lang = TERMINALS;
	while (lang[i])
	{
		if (*c == lang[i])
		{
			ft_printf("%c", *c);
		}
		i += 1;
	}
}

int			main(void)
{
	char	str[4] = {0};

	if(tswitch(1) == -1)
		return (-1);
	while (read(0, str, 3))
	{
		ft_printf("%d%d%d%d\n", str[0], str[1], str[2], str[3]);
		ft_striter(str, &is_lang);
		ft_printf("\n");
		ft_strclr(str);
	}
	tswitch(0);
	return (0);
}

