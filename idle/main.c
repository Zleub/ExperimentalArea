/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2014/01/28 15:07:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>

void					load_game(t_heros *heros)
{
	int					vic;
	int					cmp;

	cmp = 0;
	vic = 0;
	while ((cmp = playing(heros, 20, 20)))
	{
		vic += cmp;
		ft_putstr("Victoires : ");
		ft_putnbr(vic);
		ft_putendl(NULL);
		ft_putendl(NULL);
	}
	ft_putstr("You died and made ");
	ft_putnbr(vic);
	ft_putendl(" victories.");
}

t_heros					*load_heros(t_heros *heros)
{
	char				*str;
	int					fd;

	if (heros)
	{
		// free(heros->name);
		// heros->name = NULL;
		free(heros);
		heros = NULL;
	}
	ft_printf("DEBUG 1, erno : %d\n", errno);
	// if(!heros)
	heros = malloc(sizeof(t_heros));

	ft_printf("DEBUG 2\n");
	str = get_name();

	ft_printf("DEBUG 3 : str = %s\n", str);
	char *tmp = ft_strcat(str, ".sav");
	fd = open(tmp, O_RDWR);

	ft_printf("DEBUG 4 : str = %s && tmp = %s\n", str, tmp);
	if (fd < 1)
	{
		ft_printf("%s do not exists", tmp);
		return (NULL);
	}

	ft_printf("DEBUG 5 : str = %s && tmp = %s\n", str, tmp);
	// free(str);
	// str = NULL;

	ft_printf("DEBUG 6 : str = %s && tmp = %s\n", str, tmp);
	ft_printf("FD : %d\n", fd);
	// get_next_line(fd, &str);
	heros->name = ft_strdup(trim_save(tmp));

	ft_printf("DEBUG 7 : str = %s && tmp = %s\n", str, tmp);
	free (str);
	str = NULL;
	ft_printf("gnl : %d\n", get_next_line(fd, &str));
	// char *buf = NULL;
	// while (read(fd, buf, 1) > 0)
	// 	ft_printf("%s\n", buf);


	ft_printf("DEBUG 8 / str = %s\n", str);

	heros->strengh = ft_atoi(str);
	// free(str);
	get_next_line(fd, &str);

	ft_printf("DEBUG 9 / str = %s\n", str);
	heros->defense = ft_atoi(str);
	free(str);
	// get_next_line(fd, &str);
	// free(str);
	close(fd);
	return (heros);
}

void					new_game(void)
{
	char				*str;
	unsigned int		hash;
	int					fd;

	str = get_name();
	hash = hashich(str);
	fd = open(ft_strcat(str, ".sav"), O_WRONLY|O_CREAT, 00755);
	str = ft_itoa(hash % 21);
	ft_putendl_fd(str, fd);
	str = ft_itoa((hash / 21) % 21);
	ft_putendl_fd(str, fd);
	close(fd);
	free(str);
}

void					print_menu(t_heros *heros)
{
	write(1, "Hello\n", 6);
	write(1, "(N)ew game\n", 12);
	if (heros)
		write(1, "(P)lay game\n", 13);
	write(1, "(L)oad heros\n", 13);
	// write(1, "(R)egles\n", 9);
	write(1, "(E)xit\n", 8);
}

int						menu(t_heros *heros)
{
	char				*str;

	str = NULL;

	print_menu(heros);
	while (get_next_line(0, &str))
	{
		if (str[0] == 'N' || str[0] == 'n')
			new_game();
		else if (str[0] == 'P' || str[0] == 'p')
			load_game(heros);
		else if (str[0] == 'L' || str[0] == 'l')
			heros = load_heros(heros);
		if (str[0] == 'H' || str[0] == 'h')
			print_heros(heros);
		else if (str[0] == 'E' || str[0] == 'e')
			return (0);
		free(str);
		str = NULL;
		write(1, "\n", 1);
		print_menu(heros);
	}
	return (0);
}

int						main(void)
{
	return (menu(NULL));
}
