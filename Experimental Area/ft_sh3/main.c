#include <sh3.h>

#include <fcntl.h>
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

int			test(void)
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

char		*ft_mstrcat(char *str_1, char *str_2)
{
	char	*ret;
	char	*p;

	ret = (char *)malloc(ft_strlen(str_1) + ft_strlen(str_2) + 1);
	p = ret;
	while (*str_1)
		*ret++ = *str_1++;
	while (*str_2)
		*ret++ = *str_2++;
	*ret = '\0';
	return (p);
}

int			main(void)
{
	int		fd;
	int		i;
	int		start;
	char	*tmp;
	t_gnl	*head;
	t_gnl	*gram;

	if ((fd = open("test.gmr", O_RDONLY)) < 0)
		return (-1);
	start = 1;
	gram = (t_gnl*)malloc(sizeof(t_gnl));
	head = gram;
	while (get_next_line(fd, &tmp) > 0)
	{
		if (tmp[0] != '\t')
		{
			if (!start)
			{
				gram->next = (t_gnl*)malloc(sizeof(t_gnl));
				gram = gram->next;
				gram->next = NULL;
			}
			gram->str = ft_strdup(tmp);
			ft_printf("str : %s - %p\n", gram->str, gram);
			start = 0;
		}
		else
		{
			i = 0;
			while (tmp[i] == '\t')
				i += 1;
			tmp = ft_strsub(tmp, i, ft_strlen(tmp) - i);
			ft_printf("tmp : %s\n", tmp);
			gram->str = ft_mstrcat(gram->str, tmp);
		}
	}

	gram = head;
	while(gram)
	{
		ft_printf("dump : %s\n", gram->str);
		gram = gram->next;
	}
	while (42);
	return (0);
}